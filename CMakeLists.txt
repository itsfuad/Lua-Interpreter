cmake_minimum_required(VERSION 3.17)
set(project ProJect_name_here)
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
set(lua_include_dir Lua_dir) #for example "G:/Softwares/lua/include"
set(lua_lib_dir Lua_lib) #for example "G:/Softwares/lua/lib"
set(cpp_dir C++_compilers_binary_dir) #for example "G:/Softwares/MinGW64/bin"
set(CMAKE_CXX_STANDARD 17)

include_directories(${lua_include_dir})
link_directories(${lua_lib_dir})

file(COPY ${lua_lib_dir}/lua54.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
foreach(lib ${cpp_libs})
    file(COPY ${cpp_dir}/${lib} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()
add_executable(${project} main.cpp )

target_link_libraries(${project} lua54.a)
