/*
1、编写C++类
2、创建package文件，只列出所有我们希望暴露给lua使用的常数，变量，函数，类和方法
3、使用tolua++工具生成C++代码：tolua++ -o lua_export.cc export.pkg
4、可以直接编辑lua_export.cc添加自定义函数，例如要返回多个值到lua
*/

#include <stdio.h>
#include <stdlib.h>
#include "lua.hpp"
#include "tolua++.h"
#include "myclass.h"

TOLUA_API int tolua_export_open (lua_State* tolua_S);

int main(int argc, char* argv[])
{
    //创建Lua运行环境
    lua_State* L = luaL_newstate();
    if(L == NULL) {
        printf("luaL_newstate() fail!\n");
        return -1;
    }

    //加载Lua基本库
    luaL_openlibs(L);
    tolua_export_open(L);

    //加载Lua脚本
    int ret = luaL_dofile(L, "tolua_test.lua");
    if(ret != 0) {
        printf("luaL_dofile() fail!\n");
        return -1;
    }

    //调用Lua中的函数
    lua_getglobal(L, "functionA");
    lua_pushinteger(L, 11);
    lua_pushinteger(L, 22);
    ret = lua_pcall(L, 2, 1, 0);
    if(ret != 0) {
        printf("lua_pcall functionA() fail!\n");
        return -1;
    }
    //返回栈顶元素，然后清栈
    printf("c++: lua.functionA() result: %d\n", lua_tointeger(L, -1));
    lua_pop(L, 1);

    MyClass obj;
    lua_getglobal(L, "functionB");
    lua_pushlightuserdata(L, &obj);
    ret = lua_pcall(L, 1, 0, 0);
    if(ret != 0) {
        printf("lua_pcall functionB() fail!\n");
        return -1;
    }
 
    //释放Lua运行环境
    lua_close(L);
    return 0;
}
