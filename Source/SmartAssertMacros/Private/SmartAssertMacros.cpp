// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#include "SmartAssertMacros.h"

#if WITH_EDITOR
//Must define the delegates so it can be accessed outside the module with no linkage errors.
FSmartAssertMacrosModule::FOnSmartAssert FSmartAssertMacrosModule::OnSmartAssert;
FSmartAssertMacrosModule::FOnBlueprintAssert FSmartAssertMacrosModule::OnBlueprintAssert;
#endif

void FSmartAssertMacrosModule::StartupModule() { }

void FSmartAssertMacrosModule::ShutdownModule() { }

IMPLEMENT_MODULE(FSmartAssertMacrosModule, SmartAssertMacros)