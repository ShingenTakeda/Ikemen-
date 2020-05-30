include("conanbuildinfo.premake.lua")

workspace("Ikemen++")
		conan_basic_setup()

		configurations
		{
			"Debug",
			"Release",
			"Dist"
		}

		flags
		{
			"MultiProcessorCompile"
		}

		cppdialect "C++17"
	
		outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project("Ikemen++")
	kind "ConsoleApp"
		language "C++"
		targetdir "bin/%{cfg.buildcfg}"

		linkoptions { conan_exelinkflags }
		
		configuration { "linux", "gmake2" }
			linkoptions {"-no-pie"}
			
		includedirs {"%{prj.name}/src"}

		files { "src/**.hpp", "src/**.cpp" , "sol2/**.hpp"}

		filter "configurations:Debug"
			defines "DEBUG"
			runtime "Debug"
			symbols "on"
	
		filter "configurations:Release"
			defines "RELEASE"
			runtime "Release"
			optimize "on"
	
		filter "configurations:Dist"
			defines "DIST"
			runtime "Release"
			optimize "on"