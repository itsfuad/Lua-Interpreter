cmake_minimum_required(VERSION 3.17)
set(project Lua)
project(${project})

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2") #Optimiser Flag for Release
set(cpp_libs #ALL C++ Dynamic Libraries
        libatomic-1.dll
        libgcc_s_dw2-1.dll
        libgfortran-4.dll
        libgomp-1.dll
        libquadmath-0.dll
        libssp-0.dll
        libstdc++-6.dll
        libwinpthread-1.dll)
set(lua_include_dir "PATHHERE/lua/include") #Lua include PATH
set(lua_lib_dir "PATHHERE/lua") #Lua lib PATH
set(cpp_dir "PATHHERE\\mingw32\\bin") #Compiler bin PATH
set(CMAKE_CXX_STANDARD 17) #making C++ Standard 17

include_directories(${lua_include_dir}) #lua include directory
link_directories(${lua_lib_dir}) #lua library directory


file(COPY ${lua_lib_dir}/lua54.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
foreach(lib ${cpp_libs}) # copy essential libraries for the binary
    file(COPY ${cpp_dir}/${lib} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()
add_executable(${project} main.cpp )

target_link_libraries(${project} lua54.a) #linking with lua library
