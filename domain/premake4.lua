	project "domain" 
		kind "SharedLib"
		language "C++"
		targetname "helmet"
		files { "src/**.h", "src/**.cpp" }
		
	configuration { "debug" }
		targetdir (DIR_LIB_DEBUG)
		
	configuration { "release" }
		targetdir (DIR_LIB_RELEASE)
		
	project "domain-test"
		kind "ConsoleApp"
		language "C++"
		includedirs { "src/" }
		files { "test/**.h", "test/**.cpp" }
		links { "domain", "cppunit" }