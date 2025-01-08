// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSafeCheckEditor, All, All)

class FSafeCheckEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	bool OnSafeCheck(FString expression, FString file, int32 line, FString message);
	bool OnBlueprintAssert(FString message);
	bool ShouldSafeCheck();
};
