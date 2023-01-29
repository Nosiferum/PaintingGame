// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PaintingGame : ModuleRules
{
	public PaintingGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "ProceduralMeshComponent" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
