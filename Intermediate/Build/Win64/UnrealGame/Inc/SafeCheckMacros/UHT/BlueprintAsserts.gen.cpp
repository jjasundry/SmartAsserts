// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SafeCheckMacros/Public/BlueprintAsserts.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlueprintAsserts() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	SAFECHECKMACROS_API UClass* Z_Construct_UClass_UBlueprintAsserts();
	SAFECHECKMACROS_API UClass* Z_Construct_UClass_UBlueprintAsserts_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SafeCheckMacros();
// End Cross Module References
	DEFINE_FUNCTION(UBlueprintAsserts::execBlueprintAssert)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_message);
		P_FINISH;
		P_NATIVE_BEGIN;
		UBlueprintAsserts::BlueprintAssert(Z_Param_message);
		P_NATIVE_END;
	}
	void UBlueprintAsserts::StaticRegisterNativesUBlueprintAsserts()
	{
		UClass* Class = UBlueprintAsserts::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BlueprintAssert", &UBlueprintAsserts::execBlueprintAssert },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics
	{
		struct BlueprintAsserts_eventBlueprintAssert_Parms
		{
			FString message;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_message;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::NewProp_message = { "message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintAsserts_eventBlueprintAssert_Parms, message), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::NewProp_message,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::Function_MetaDataParams[] = {
		{ "Category", "Asserts" },
		{ "Comment", "// Crash the PIE session. Avoids crashing the entire editor like a normal assert. Don't execute this node outside the game!\n" },
		{ "DisplayName", "Assert" },
		{ "ModuleRelativePath", "Public/BlueprintAsserts.h" },
		{ "ToolTip", "Crash the PIE session. Avoids crashing the entire editor like a normal assert. Don't execute this node outside the game!" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBlueprintAsserts, nullptr, "BlueprintAssert", nullptr, nullptr, Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::BlueprintAsserts_eventBlueprintAssert_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::BlueprintAsserts_eventBlueprintAssert_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBlueprintAsserts);
	UClass* Z_Construct_UClass_UBlueprintAsserts_NoRegister()
	{
		return UBlueprintAsserts::StaticClass();
	}
	struct Z_Construct_UClass_UBlueprintAsserts_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBlueprintAsserts_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SafeCheckMacros,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintAsserts_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UBlueprintAsserts_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBlueprintAsserts_BlueprintAssert, "BlueprintAssert" }, // 1306274207
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintAsserts_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlueprintAsserts_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BlueprintAsserts.h" },
		{ "ModuleRelativePath", "Public/BlueprintAsserts.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBlueprintAsserts_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlueprintAsserts>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlueprintAsserts_Statics::ClassParams = {
		&UBlueprintAsserts::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintAsserts_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlueprintAsserts_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBlueprintAsserts()
	{
		if (!Z_Registration_Info_UClass_UBlueprintAsserts.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlueprintAsserts.OuterSingleton, Z_Construct_UClass_UBlueprintAsserts_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBlueprintAsserts.OuterSingleton;
	}
	template<> SAFECHECKMACROS_API UClass* StaticClass<UBlueprintAsserts>()
	{
		return UBlueprintAsserts::StaticClass();
	}
	UBlueprintAsserts::UBlueprintAsserts(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBlueprintAsserts);
	UBlueprintAsserts::~UBlueprintAsserts() {}
	struct Z_CompiledInDeferFile_FID_ArcaneArsenal_PackagedPlugins_SafeCheck_SafeCheck_HostProject_Plugins_SafeCheck_Source_SafeCheckMacros_Public_BlueprintAsserts_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArcaneArsenal_PackagedPlugins_SafeCheck_SafeCheck_HostProject_Plugins_SafeCheck_Source_SafeCheckMacros_Public_BlueprintAsserts_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBlueprintAsserts, UBlueprintAsserts::StaticClass, TEXT("UBlueprintAsserts"), &Z_Registration_Info_UClass_UBlueprintAsserts, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlueprintAsserts), 5936987U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArcaneArsenal_PackagedPlugins_SafeCheck_SafeCheck_HostProject_Plugins_SafeCheck_Source_SafeCheckMacros_Public_BlueprintAsserts_h_2653265442(TEXT("/Script/SafeCheckMacros"),
		Z_CompiledInDeferFile_FID_ArcaneArsenal_PackagedPlugins_SafeCheck_SafeCheck_HostProject_Plugins_SafeCheck_Source_SafeCheckMacros_Public_BlueprintAsserts_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArcaneArsenal_PackagedPlugins_SafeCheck_SafeCheck_HostProject_Plugins_SafeCheck_Source_SafeCheckMacros_Public_BlueprintAsserts_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
