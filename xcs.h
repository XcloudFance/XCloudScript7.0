#include<cstdio>
#include<iostream>
#include<vector>
#include<cassert>
#include<cstring>
#include<fstream>
#include"Windows.h"
#include<cstdlib>
#include<ctime>
using namespace std;
string coding;
 string cppcoding;
inline string subfront(string s)
{
	int p=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=' ')break;
		p++;
	}
	return	s.substr(p,s.length());
} 
inline string subback(string s)
{
	int p=s.length();
	for(int i=s.length()-1;i>0;i--)
	{
		if(s[i]!=' ')break;
		p--;
	}
	return s.substr(0,p);
} 
inline void getcode()
{
		string file="code.txt";
	    ifstream infile; 
	    infile.open(file.data());   //将文件流对象与文件连接起来 
	    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	
	    string s;
	    while(getline(infile,s))
	    {
	    	s=subback(subfront(s));
	    	coding+=s;
	    	string tmp[1000];
	    	int tmp1=0;
			for(char i : s)	
				if(i!=' ')
					tmp[tmp1%1000]+=i;
				else 
				if(tmp[tmp1]!="")
				tmp1++;
			cout<<tmp1<<endl;
			if(tmp[0]=="provide")
			{
					if(tmp[1]=="normal")
					{
						cppcoding+="#include\"grammer.h\"\n";
						cppcoding+="#include\"xcs.h\"\n"; 
						cppcoding+="#include\"function.h\"\n"; 
						cppcoding+="#include\"normal.h\"\n"; 
						cppcoding+="#include\"compile.h\"\n"; 
						cppcoding+="using namespace std;\n";
						cppcoding+="int main(void){\n";
						cppcoding+="ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);\n";
						continue;
					}
			}
		
	       	cppcoding+=s;
	       	 
	       	if(getfuncname(s)!="for" && getfuncname(s)!="formem" && getfuncname(s)!="fornum")
	       	{
	       		cppcoding+=";";
	       	}
	       	cppcoding+="\n";
	    }
	    infile.close();             //关闭文件输入流 
	
}
inline void explain()
{
	getcode();
}
inline void filein(string filename)
{
	freopen(filename.data(),"r",stdin);
}
inline void fileout(string filename)
{
	freopen(filename.data(),"w",stdout);
}
inline void hello()
{
	cout<<"helloXCS!"<<endl; 
}

