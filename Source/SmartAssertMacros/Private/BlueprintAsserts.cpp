// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#include "BlueprintAsserts.h"
#include "SmartAssertMacros.h"

void UBlueprintAsserts::BlueprintAssert(FString message)
{
#if WITH_EDITOR
	if (!(FSmartAssertMacrosModule::OnBlueprintAssert.IsBound() && FSmartAssertMacrosModule::OnBlueprintAssert.Execute(message)))
	{
		checkf(false, TEXT("%s"), *message);
	}
#else
	checkf(false, TEXT("%s"), *message);
#endif
}