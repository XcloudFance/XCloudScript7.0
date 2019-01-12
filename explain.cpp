#include "grammer.h"
#include "xcs.h"
#include "normal.h"
#include "function.h"
#include "compile.h"
#include "file.h"
using namespace std;
int main()
{
	Stringbuilder code="First Order";
	cout<<"欢迎使用XCloudScript 内部代号:"+str(code)+"版本!"<<endl; 
	ios::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
	explain();
	cppcoding+="}\n";
	cout<<"正在编译……"<<endl; 
	clock_t start=clock();
	compile(cppcoding);
	clock_t end=clock();
	cout<<"编译完成! 编译共消耗了:"<<(double)(end - start)/ CLOCKS_PER_SEC<<"s"<<endl; 
} 
