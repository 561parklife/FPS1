// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPS1 : ModuleRules
{
	public FPS1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PrivateDependencyModuleNames.AddRange(new string[] { "slua_unreal", "slua_profile", "Slate", "SlateCore", "UMG", "HTTP" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });
        PublicIncludePathModuleNames.AddRange(new string[] { "slua_unreal", "slua_profile" });
        PublicDefinitions.Add("ENABLE_PROFILER");
    }
}
