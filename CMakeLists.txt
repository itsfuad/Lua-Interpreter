cmake_minimum_required(VERSION 3.17)
set(project Lua)
project(${project})
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")
set(cpp_libs
        libatomic-1.dll
        libgcc_s_dw2-1.dll
        libgfortran-4.dll
        libgomp-1.dll
        libquadmath-0.dll
        libssp-0.dll
        libstdc++-6.dll
        libwinpthread-1.dll)
set(lua_include_dir "G:/Softwares/C++ Compiler/lua/include")
set(lua_lib_dir "G:/Softwares/C++ Compiler/lua")
set(cpp_dir "G:\\Softwares\\C++ Compiler\\mingw32\\bin")
set(CMAKE_CXX_STANDARD 17)

include_directories(${lua_include_dir})
link_directories(${lua_lib_dir})

file(COPY ${lua_lib_dir}/lua54.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
foreach(lib ${cpp_libs})
    file(COPY ${cpp_dir}/${lib} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()
add_executable(${project} main.cpp )

target_link_libraries(${project} winmm.a lua54.a)