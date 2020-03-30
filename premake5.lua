include("conanbuildinfo.premake.lua")

workspace("Ikemen++")
		conan_basic_setup()

project("Ikemen++")
	kind "ConsoleApp"
		language "C++"
		targetdir "bin/%{cfg.buildcfg}"

		linkoptions { conan_exelinkflags }

		files { "src/**.h", "src/**.cpp" }

		filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

		filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
