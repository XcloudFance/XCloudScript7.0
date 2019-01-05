#include <iostream>
#include <stdio.h>  

extern "C" {
//#include "lprefix.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

using namespace std;

lua_State* L;

static int average(lua_State *L)
{
    //����ջ��Ԫ�صĸ���  
    int n = lua_gettop(L);
    double sum = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (!lua_isnumber(L, i))
        {
            lua_pushstring(L, "Incorrect argument to 'average'");
            lua_error(L);
        }
        sum += lua_tonumber(L, i);
    }
    /* push the average */
    lua_pushnumber(L, sum / n);
    /* push the sum */
    lua_pushnumber(L, sum);

    /* return the number of results */
    return 2;
}

int main()
{
    //cout << "Hello CML" << endl;

    /* ��ʼ�� Lua */
    L = luaL_newstate();

    /* ����Lua������ */
    luaL_openlibs(L);

    /* register our function */
    lua_register(L, "average", average);

    /* ���нű� */
    luaL_dofile(L, "e://lua1.lua");

    lua_getglobal(L, "avg");
    int avg = lua_tointeger(L, -1);
    lua_pop(L, 1);
    lua_getglobal(L, "sum");
    int sum = lua_tointeger(L, -1);

    lua_getglobal(L, "add");
    lua_pushinteger(L, 10);
    lua_pushinteger(L, 20);
    lua_pcall(L, 2, 1, 0);
    printf("lua add function return val is %d \n", lua_tointeger(L, -1));

    /* ���Lua */
    lua_close(L);

    /* ��ͣ */
    printf("Press enter to exit��");
    getchar();
}

