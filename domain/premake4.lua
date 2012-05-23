	project "domain" 
		kind "StaticLib"
		language "C++"
		targetname "helmet"
		includedirs { "includes/" }
		files { "src/**.h", "src/**.cpp" }
		
	configuration { "debug" }
		targetdir (DIR_LIB_DEBUG)
		
	configuration { "release" }
		targetdir (DIR_LIB_RELEASE)
		
	project "domain-test"
		kind "ConsoleApp"
		language "C++"
		includedirs { "includes/" }
		files { "test/**.h", "test/**.cpp" }
		links { "domain", "cppunit" }