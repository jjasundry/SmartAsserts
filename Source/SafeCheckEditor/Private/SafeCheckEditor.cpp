// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#include "SafeCheckEditor.h"
#include "SafeCheckMacros/Public/SafeCheckMacros.h"
#include "Kismet2/KismetDebugUtilities.h"
#include "Logging/MessageLog.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealEd.h"
#include "UObject/Stack.h"
#if ENGINE_MINOR_VERSION == 5
#include "Blueprint/BlueprintExceptionInfo.h"
#else
#include "UObject/Script.h"
#endif

#ifndef FirstFrameSimulateBug
	#define FirstFrameSimulateBug true
#endif

DEFINE_LOG_CATEGORY(LogSafeCheckEditor)

void FSafeCheckEditorModule::StartupModule()
{
#if WITH_EDITOR
	FSafeCheckMacrosModule::OnSafeCheck.BindRaw(this, &FSafeCheckEditorModule::OnSafeCheck);
	FSafeCheckMacrosModule::OnBlueprintAssert.BindRaw(this, &FSafeCheckEditorModule::OnBlueprintAssert);
	UE_LOG(LogSafeCheckEditor, Log, TEXT("Smart Asserts enabled"));
#else
	UE_LOG(LogSafeCheckEditor, Error, TEXT("Editor module loaded without the editor. Don't know how this is possible, but SafeChecks will not be enabled."));
#endif
}

void FSafeCheckEditorModule::ShutdownModule()
{
#if WITH_EDITOR
	FSafeCheckMacrosModule::OnSafeCheck.Unbind();
	FSafeCheckMacrosModule::OnBlueprintAssert.Unbind();
	UE_LOG(LogSafeCheckEditor, Log, TEXT("Smart Asserts disabled"));
#else
	UE_LOG(LogSafeCheckEditor, Error, TEXT("Editor module unloaded without the editor. Don't know how this is possible, but SafeChecks will not be disabled (they also shouldn't have been enabled already)."));
#endif
}

bool FSafeCheckEditorModule::OnSafeCheck(FString expression, FString file, int32 line, FString message)
{
	if (!ShouldSafeCheck())
		return false;

	//Log the message to the more designer-friendly logger.
	FMessageLog PIELogger = FMessageLog(FName("PIE")); 
	FString PIEMessage = FString::Printf(TEXT("Assertion failed: %s %s [Line: %d]"), *expression, *file, line);
	if (!message.IsEmpty()) //avoids adding the new line if the message is blank.
	{
		PIEMessage.Appendf(TEXT("\n%s"), *message);
	}
	PIELogger.Error(FText::FromString(PIEMessage));

	//Stop execution of the blueprint, making it "crash" in the middle of a frame.
	//Normally this would put the game into debug mode
	FKismetDebugUtilities::RequestSingleStepIn(); 
	//Quit the game. This works even when the editor gets paused, so the user won't notice it went into debug mode.
	UKismetSystemLibrary::QuitGame(GEngine->GameViewport->GetWorld(), nullptr, EQuitPreference::Quit, false); //Stop execution of the game

	return true;
}

bool FSafeCheckEditorModule::OnBlueprintAssert(FString message)
{
	if (!ShouldSafeCheck())
		return false;
	
	//Format the message for the logger and default it if the user-provided message is empty.
	FText SanitizedMessage;
	if (message.IsEmpty())
	{
		SanitizedMessage = NSLOCTEXT("SafeCheck", "BlueprintAssertEmptyMessage", "Blueprint asserted");
	}
	else
	{
		SanitizedMessage = FText::FromString(message);
	}

	//Tell the PIE logger an error happened. It will automatically append links to the node and blueprint the error occured in.
	FBlueprintExceptionInfo ExceptionInfo(
		EBlueprintExceptionType::AccessViolation,
		SanitizedMessage
	);
	FBlueprintCoreDelegates::ThrowScriptException(FFrame::GetThreadLocalTopStackFrame()->Object, *FFrame::GetThreadLocalTopStackFrame(), ExceptionInfo);

	//Stop execution of the blueprint, making it "crash" in the middle of a frame.
	//Normally this would put the game into debug mode
	FKismetDebugUtilities::RequestSingleStepIn();
	//Quit the game. This works even when the editor gets paused, so the user won't notice it went into debug mode.
	UKismetSystemLibrary::QuitGame(GEngine->GameViewport->GetWorld(), nullptr, EQuitPreference::Quit, false); //Stop execution of the game

	return true;
}

bool FSafeCheckEditorModule::ShouldSafeCheck()
{
	return (GEngine && //Make sure there is a valid game world
			GEngine->GameViewport &&
			GEngine->GameViewport->GetWorld() &&
			FFrame::GetThreadLocalTopStackFrame() && //Make sure the logic originates in a blueprint
			FFrame::GetThreadLocalTopStackFrame()->Node &&
			UGameplayStatics::GetGameInstance(GEngine->GameViewport->GetWorld()) && //Make sure the game is running, ei there is a game instance.
			GEditor && //Make sure the engine is valid (don't know why it wouldn't)
			GEditor->IsPlayingSessionInEditor() //Make sure either PIE or SIE is running.
#if FirstFrameSimulateBug
			&& !(GEditor->IsSimulatingInEditor() && GEngine->GameViewport->GetWorld()->GetRealTimeSeconds() < 0.001) //There is an error in unreal where if QuitGame is called in the first frame of SIE, the editor crashes when exiting up the game.
#endif
		); 
}
	
IMPLEMENT_MODULE(FSafeCheckEditorModule, SafeCheckEditor)