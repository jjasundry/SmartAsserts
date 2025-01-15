// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintAsserts.generated.h"

/**
 * 
 */
UCLASS()
class UBlueprintAsserts : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// Crash the PIE session. Avoids crashing the entire editor like a normal assert. Don't execute this node outside the game!
	UFUNCTION(BlueprintCallable, Category = "Asserts", meta = (DisplayName = "Assert"))
	static void BlueprintAssert(FString message);
};
