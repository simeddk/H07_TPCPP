using UnrealBuildTool;

public class H07_TPSCPP : ModuleRules
{
	public H07_TPSCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		//PublicDependencyModuleNames.AddRange(new string[] 
		//{ 
		//	"Core",
		//	"CoreUObject",
		//	"Engine",
		//	"InputCore" 
		//});

		PublicDependencyModuleNames.Add("Core");
		PublicDependencyModuleNames.Add("CoreUObject");
		PublicDependencyModuleNames.Add("Engine");
		PublicDependencyModuleNames.Add("InputCore");

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.Add(ModuleDirectory);
	}
}
