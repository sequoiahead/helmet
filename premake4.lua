-- A solution contains projects, and defines the available configurations
solution "helmet"
	configurations { "debug", "release" }
	location "target/build"
 
	-- A project defines one build target
	project "helmet"
		kind "WindowedApp"
		language "C++"
		files { "src/main/**.h", "src/main/**.cpp" }
 
	configuration "debug"
		defines { "_DEBUG" }
		targetdir "target/bin/debug"
 
	configuration "release"
		defines { "_RELEASE" }
		targetdir "target/bin/release"

if _ACTION == "clean" then
	os.rmdir("target")
end
