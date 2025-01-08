// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SafeCheckMacros : ModuleRules
{
	public SafeCheckMacros(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {});
				
		
		PrivateIncludePaths.AddRange(new string[] {});
			
		
		PublicDependencyModuleNames.AddRange(new string[] {});
			
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {});
	}
}
