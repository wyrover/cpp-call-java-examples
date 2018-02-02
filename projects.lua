BOOK_CODE_PATH = "E:/book-code"
THIRD_PARTY = "E:/book-code/3rdparty"
WORK_PATH = os.getcwd()
includeexternal (BOOK_CODE_PATH .. "/premake-vs-include.lua")




workspace(path.getname(os.realpath(".")))
    language "C++"
    location "build/%{_ACTION}/%{wks.name}"    
    if _ACTION == "vs2015" then
        toolset "v140_xp"
    elseif _ACTION == "vs2013" then
        toolset "v120_xp"
    end

    --include (BOOK_CODE_PATH .. "/common.lua")    
    


    function create_example_project(name, dir)        
        project(name)          
        kind "ConsoleApp"                                             
        files
        {                                  
            dir .. "/%{prj.name}/**.h",
            dir .. "/%{prj.name}/**.cpp", 
            dir .. "/%{prj.name}/**.c", 
            dir .. "/%{prj.name}/**.rc",    
            "3rdparty/CJay/CJay/CJay.cpp",
            "3rdparty/CJay/CJay/CJay.hpp",
        }
        removefiles
        {               
        }
        includedirs
        {               
            "C:/Java/jdk/include",
            "C:/Java/jdk/include/win32",
            "3rdparty/CJay/CJay"
           
        }         
        has_stdafx(name, dir)               
    end    
    

    
       
    group "examples"
    
        create_example_project("example01", "src")
        create_example_project("example02", "src")
       