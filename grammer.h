#include<string>
using namespace std;
string getfuncname(string line)
{
	string res="";
	for(int i=0;i<line.length();i++)
	{
		if(line[i]=='(')break;
		res+=line[i];
	}
	return res;
}
string judge1(string line)//判断当前此行代码是否为赋值 
{
	
}
string judge2(string line)//判断当前此行代码是否为函数 
{
	
} 
string judge3(string line)//判断赋值号后面的变量类型 
{
	
} 
