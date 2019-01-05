
    #include <iostream>  
    #include <string.h>  
    using namespace std;  
      
    extern "C"  
    {  
        #include <lua.h>
        #include <lauxlib.h>
        #include<lualib.h> 
    }  
    int main()  
    {  
        //1.����һ��state  
        lua_State *L = luaL_newstate();  
          
        //2.��ջ����  
        lua_pushstring(L, "I am so cool~");   
        lua_pushnumber(L,20);  
      
        //3.ȡֵ����  
        if( lua_isstring(L,1)){             //�ж��Ƿ����תΪstring  
            cout<<lua_tostring(L,1)<<endl;  //תΪstring������  
        }  
        if( lua_isnumber(L,2)){  
            cout<<lua_tonumber(L,2)<<endl;  
        }  
      
        //4.�ر�state  
        lua_close(L);  
        return 0 ;  
    }  
