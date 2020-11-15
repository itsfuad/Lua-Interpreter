/*
    Author: Fuad Hasan
    Type: Interpreter
    Date: November 14, 2020
    This is a lua intrpreter. If you copy or modify this code then give me a little credit.
    Happy Coding..!
*/
#include <iostream>
#include <lua.hpp>
void intr(), exit(), help(), compile();
lua_State* Lua = luaL_newstate();

void help(){
    std::cout << "\t\t\t[Help]\n\n";
    std::cout << "--intr\t\t[Turn on Interpreter mode]\n";
    std::cout << "exit\t\t[Exit Lua]\n";
    std::cout << "Lua [filename.lua]  [Run Lua Script]\n";
    std::cout << "[i] [interpreter mode]\n";
    std::cout << "[n] [normal mode]\n\n";
}
void intr(){
    luaL_openlibs(Lua);
    std::string itr_text;
    std::cout << "[i]>>> ";
    getline(std::cin, itr_text);
    if(itr_text == std::string("exit")){
        exit();
    }
    else if(itr_text == std::string("--help")){
        help();
    }
    if(luaL_dostring(Lua, itr_text.c_str()) == LUA_OK){} //Run The script
    else{std::cout << lua_tostring(Lua, -1) << std::endl;} //Show error messages
    intr();
}
void exit(){
    exit(0);
}
void compile(const char* inp){
    luaL_openlibs(Lua);
    if(luaL_dofile(Lua, inp) == LUA_OK){} //Run The script
    else{std::cout << lua_tostring(Lua, -1) << std::endl;} //Show error messages
}
int main(int argc, char* argv[]) {
    op1:
    if(argc == 1){
        ///Open with no param
        std::string inp;
        std::cout << "[n]>>> ";
        getline(std::cin, inp);
        if(inp == std::string("--help")){
            help();
            goto op1;
        }
        else if(inp == std::string("--intr")){
            intr();
            goto op1;
        }
        else if(inp == std::string("exit")){
            exit();
        }
        compile(inp.c_str());
    }
    else{
        ///Open with param
        if(argv[1] == std::string("--help")){
            help();
            argc = 1;
            goto op1;
        }
        else if(argv[1] == std::string("--intr")){
            intr();
            argc = 1;
            goto op1;
        }
        else if(argv[1] == std::string("exit")){
            exit();
        }
        else{
            compile(argv[1]);
        }
    }
}
