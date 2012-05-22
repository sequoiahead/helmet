	project "main"
		kind "WindowedApp"
		language "C++"
		targetname "helmet"
		files { "src/**.h", "src/**.cpp" }
		links { "domain" }