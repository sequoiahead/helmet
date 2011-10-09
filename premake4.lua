DIR_TARGET = "target"  
DIR_BIN_DEBUG = DIR_TARGET .. "/debug/bin" 
DIR_BIN_RELEASE = DIR_TARGET .. "/release/bin" 
DIR_LIB_DEBUG = DIR_TARGET .. "/debug/lib" 
DIR_LIB_RELEASE = DIR_TARGET .. "/release/lib" 

solution "helmet"
	configurations { "debug", "release" }
	flags { "FatalWarnings", "ExtraWarnings" }
	location (DIR_TARGET)
	
	configuration { "debug" }
		defines { "_DEBUG" }
		flags { "Symbols" }
		libdirs { (DIR_LIB_DEBUG .. "/**") }
		targetdir (DIR_BIN_DEBUG)
		
	configuration { "release" }
		defines { "_RELEASE" }
		flags { "OptimizeSpeed" }
		libdirs { (DIR_LIB_RELEASE .. "/**") }
		targetdir (DIR_BIN_RELEASE)
		
	project "helmet-main"
		kind "WindowedApp"
		language "C++"
		targetname "helmet"
		files { "src/main/**.h", "src/main/**.cpp" }
		links { "helmet" }
				
	project "helmet" 
		kind "StaticLib"
		language "C++"
		files { "src/libhelmet/**.h", "src/libhelmet/**.cpp" }
		
	configuration { "debug" }
		targetdir (DIR_LIB_DEBUG)
		
	configuration { "release" }
		targetdir (DIR_LIB_RELEASE)

	project "test_libhelmet"
		kind "ConsoleApp"
		language "C++"
		includedirs { "src/libhelmet" }
		files { "src/test/**.h", "src/test/**.cpp" }
		links { "helmet", "cppunit" }
		
if _ACTION == "clean" then
	os.rmdir(DIR_TARGET)
end