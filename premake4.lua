DIR_BUILD = os.getcwd() .. "/build"
DIR_BIN_DEBUG = DIR_BUILD .. "/debug/bin" 
DIR_BIN_RELEASE = DIR_BUILD .. "/release/bin" 
DIR_LIB_DEBUG = DIR_BUILD .. "/debug/lib" 
DIR_LIB_RELEASE = DIR_BUILD .. "/release/lib" 

solution "helmet"
	configurations { "debug", "release" }
	flags { "FatalWarnings", "ExtraWarnings" }
	location (DIR_BUILD)
	
	configuration { "debug" }
		defines { "_DEBUG" }
		flags { "Symbols" }
		targetdir (DIR_BIN_DEBUG)
		
	configuration { "release" }
		defines { "_RELEASE" }
		flags { "OptimizeSpeed" }
		targetdir (DIR_BIN_RELEASE)
	
	include "libhelmet"
	include "ui-cli"
	include "ui-gtk"

if _ACTION == "clean" then
	os.rmdir(DIR_BUILD)
end

newaction {
   trigger     = "clean-ide",
   description = "Remove all IDE-specific files",
   execute = function ()
      local ide_resources = {".cproject", ".settings/", ".classpath", ".externalToolBuilders/", ".project"}
		for i,res in ipairs(ide_resources) do
			os.rmdir(res)
		end
   end
}