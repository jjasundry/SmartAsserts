// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SafeCheckEditor : ModuleRules
{
	public SafeCheckEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {});
				
		
		PrivateIncludePaths.AddRange(new string[] {});
			
		
		PublicDependencyModuleNames.AddRange(new string[] {});
			
		
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "SafeCheckMacros", "UnrealEd", "CoreUObject", "Engine"});
		
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {});
	}
}
