// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#include "SafeCheckMacros.h"

#if WITH_EDITOR
//Must define the delegates so it can be accessed outside the module with no linkage errors.
FSafeCheckMacrosModule::FOnSafeCheck FSafeCheckMacrosModule::OnSafeCheck;
FSafeCheckMacrosModule::FOnBlueprintAssert FSafeCheckMacrosModule::OnBlueprintAssert;
#endif

void FSafeCheckMacrosModule::StartupModule() { }

void FSafeCheckMacrosModule::ShutdownModule() { }

IMPLEMENT_MODULE(FSafeCheckMacrosModule, SafeCheckMacros)