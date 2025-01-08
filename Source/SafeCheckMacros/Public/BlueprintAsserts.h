// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintAsserts.generated.h"

/**
 * 
 */
UCLASS()
class SAFECHECKMACROS_API UBlueprintAsserts : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Asserts", meta = (DisplayName = "Assert"))
	static void BlueprintAssert(FString message);
};
