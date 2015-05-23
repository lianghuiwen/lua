/*
** Lua binding: export
** Generated automatically by tolua++-1.0.92 on 05/05/15 17:43:18.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
int  tolua_export_open (lua_State* tolua_S);

#include "lua_interface.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: SetNumber */
#ifndef TOLUA_DISABLE_tolua_export_SetNumber00
static int tolua_export_SetNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  void* obj = ((void*)  tolua_touserdata(tolua_S,1,0));
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   SetNumber(obj,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,(char*)"#ferror in function 'SetNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNumber */
#ifndef TOLUA_DISABLE_tolua_export_GetNumber00
static int tolua_export_GetNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isuserdata(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  void* obj = ((void*)  tolua_touserdata(tolua_S,1,0));
  {
   int tolua_ret = (int)  GetNumber(obj);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,(char*)"#ferror in function 'GetNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
int tolua_export_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,(char*)"SetNumber",tolua_export_SetNumber00);
  tolua_function(tolua_S,(char*)"GetNumber",tolua_export_GetNumber00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 int luaopen_export (lua_State* tolua_S) {
 return tolua_export_open(tolua_S);
};
#endif

