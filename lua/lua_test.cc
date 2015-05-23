/*
1、创建Lua运行环境
2、加载Lua基本库
3、加载Lua脚本
4、注册C++函数
5、调用Lua函数
*/

#include <stdio.h>
#include <stdlib.h>
#include "lua.hpp"

static int Sum(lua_State *L)
{
    printf("c++: sum()\n");
    int sum = 0;
    int n = lua_gettop(L);
    for (int i=1; i<=n; ++i) {
        sum += lua_tointeger(L, i);
    }
    lua_pushinteger(L, sum);
    return 1;
}

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

    //加载Lua脚本
    int ret = luaL_dofile(L, "lua_test.lua");
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
        printf("lua_pcall functionA fail!\n");
        return -1;
    }
    //返回栈顶元素，然后清栈
    printf("c++: lua.functionA() result: %d\n", lua_tointeger(L, -1));
    lua_pop(L, 1);

    //注册函数
    lua_register(L, "Sum", Sum);
    lua_getglobal(L, "functionB");
    ret = lua_pcall(L, 0, 0, 0);
    if(ret != 0) {
        printf("lua_pcall functionB fail!\n");
        return -1;
    }
 
    //释放Lua运行环境
    lua_close(L);
    return 0;
}
