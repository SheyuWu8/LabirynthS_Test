// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LabirynthS_Test : ModuleRules
{
	public LabirynthS_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
