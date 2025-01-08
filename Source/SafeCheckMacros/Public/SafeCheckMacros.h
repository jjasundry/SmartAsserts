// Copyright 2024-2025 JJA Sundry, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSafeCheckMacrosModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if WITH_EDITOR
	//Needs to return false if the editor is not eligible for SafeCheck
	//All asserts will call delegates so the actual logic for asserting can be in a seperate editor module. Otherwise this runtime module will reference editor modules, causing problems when shipping.
	DECLARE_DELEGATE_RetVal_FourParams(bool, FOnSafeCheck, FString, FString, int32, FString);
	DECLARE_DELEGATE_RetVal_OneParam(bool, FOnBlueprintAssert, FString);
	static SAFECHECKMACROS_API FOnSafeCheck OnSafeCheck;
	static SAFECHECKMACROS_API FOnBlueprintAssert OnBlueprintAssert;
#endif
};

#ifndef scheck
	#if WITH_EDITOR
		#define scheck(expr) \
			if (UNLIKELY(!(expr))) \
			{ \
				if (!(FSafeCheckMacrosModule::OnSafeCheck.IsBound() && FSafeCheckMacrosModule::OnSafeCheck.Execute(FString(#expr), FString(__FILE__), __LINE__, TEXT("")))) \
				{ \
					if (FDebug::CheckVerifyFailedImpl(#expr, __FILE__, __LINE__, PLATFORM_RETURN_ADDRESS(), TEXT(""))) \
					{ \
						PLATFORM_BREAK(); \
					} \
					CA_ASSUME(false); \
				} \
				else { return; } \
			}
	#else
		#define scheck(expr) check(expr);
	#endif WITH_EDITOR
#endif scheck

#ifndef srcheck
	#if WITH_EDITOR
		#define srcheck(expr, return_value) \
			if (UNLIKELY(!(expr))) \
			{ \
				if (!(FSafeCheckMacrosModule::OnSafeCheck.IsBound() && FSafeCheckMacrosModule::OnSafeCheck.Execute(FString(#expr), FString(__FILE__), __LINE__, TEXT("")))) \
				{ \
					if (FDebug::CheckVerifyFailedImpl(#expr, __FILE__, __LINE__, PLATFORM_RETURN_ADDRESS(), TEXT(""))) \
					{ \
						PLATFORM_BREAK(); \
					} \
					CA_ASSUME(false); \
				} \
				else { return return_value; } \
			}
	#else
		#define srcheck(expr, return_value) check(expr);
	#endif WITH_EDITOR
#endif srcheck

#ifndef scheckf
	#if WITH_EDITOR
		#define scheckf(expr, format,  ...) \
			if (UNLIKELY(!(expr))) \
			{ \
				if (!(FSafeCheckMacrosModule::OnSafeCheck.IsBound() && FSafeCheckMacrosModule::OnSafeCheck.Execute(FString(#expr), FString(__FILE__), __LINE__, FString::Printf(format, ##__VA_ARGS__)))) \
				{ \
					if (FDebug::CheckVerifyFailedImpl(#expr, __FILE__, __LINE__, PLATFORM_RETURN_ADDRESS(), format, ##__VA_ARGS__)) \
					{ \
						PLATFORM_BREAK(); \
					} \
					CA_ASSUME(false); \
				} \
				else { return; } \
			}
	#else
		#define scheckf(expr, format,  ...) checkf(expr, format,  ...);
	#endif WITH_EDITOR
#endif scheckf

#ifndef srcheckf
	#if WITH_EDITOR
		#define srcheckf(expr, return_value, format,  ...) \
			if (UNLIKELY(!(expr))) \
			{ \
				if (!(FSafeCheckMacrosModule::OnSafeCheck.IsBound() && FSafeCheckMacrosModule::OnSafeCheck.Execute(FString(#expr), FString(__FILE__), __LINE__, FString::Printf(format, ##__VA_ARGS__)))) \
				{ \
					if (FDebug::CheckVerifyFailedImpl(#expr, __FILE__, __LINE__, PLATFORM_RETURN_ADDRESS(), format, ##__VA_ARGS__)) \
					{ \
						PLATFORM_BREAK(); \
					} \
					CA_ASSUME(false); \
				} \
				else { return return_value; } \
			}
	#else
		#define srcheckf(expr, return_value, format,  ...) checkf(expr, format,  ...);
	#endif WITH_EDITOR
#endif srcheckf