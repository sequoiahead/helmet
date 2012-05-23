DIR_TARGET = os.getcwd() .. "/target"
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
	
	include "domain"
	include "ui-cli"
	include "ui-gtk"
	include "main"

if _ACTION == "clean" then
	os.rmdir(DIR_TARGET)
end