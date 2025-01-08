// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#include "BlueprintAsserts.h"
#include "SafeCheckMacros.h"

void UBlueprintAsserts::BlueprintAssert(FString message)
{
#if WITH_EDITOR
	if (!(FSafeCheckMacrosModule::OnBlueprintAssert.IsBound() && FSafeCheckMacrosModule::OnBlueprintAssert.Execute(message)))
	{
		checkf(false, TEXT("%s"), *message);
	}
#else
	checkf(false, TEXT("%s"), *message);
#endif
}