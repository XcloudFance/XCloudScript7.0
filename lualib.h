extern "C"
{
#include<lua.h>
#include<lauxlib.h>
#include<lualib.h> 
}
#include<string>
#include<fstream> 
lua_State *L = luaL_newstate();
inline void lua_run(Stringbuilder coding)
{
	lua_settop(L,0);
	if(L == NULL)
    {
       cout<<"Error XCS-lua!"<<endl;
       return;
    }
    luaL_openlibs(L);
	io fs;
	string cd=coding.tostr(); 
	fs.WriteText("XCS.lua","function func()\n"+cd+"\nend");
    luaL_openlibs(L);
    int ret = luaL_dofile(L ,"XCS.lua");
    if(ret)
    {
       cout<<"XCS-lua File error!"<<endl;
       return ;
    }
    lua_getglobal(L, "func");   //函数名为ruler
    lua_pcall(L,0,0,0);          //用保护模式调用lua函数，入参个数为0、出参个数为0、无自定义错误处理
    lua_close(L);
	 
} 
class luaint{
	private:
	Stringbuilder content;
	public:
	luaint& operator = (const Stringbuilder s)
	{
		this->content=s;
		return *this;
	}
	luaint& operator + (const luaint&str)
	{
		lua_run("function add(a,b)\nreturn(tonumber(a)+tonumber(b))\nend\nadd(");//+this->content+","+str.content+")");
	}
	friend istream& operator>>(istream &is, luaint &str)//重载cin  注意友元函数
	{
		char tem[9000];  //简单的申请一块内存
		is >> tem;
		str.content=tem;
		return is;
	}
	friend ostream& operator<<(ostream &os,  const luaint &str)//重载cout
	{
		os << str.content;
		return os;
	}
}; 


