#include "grammer.h"
#include "xcs.h"
#include "normal.h"
#include "function.h"
#include "compile.h"
#include "file.h"
#include "lualib.h" 
using namespace std;
int main()
{
	cout<<"前排提示：进入XCS的加速级别，可能会出现runtime类无法精确计时的情况!"<<endl; 
	ios::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
	outf("233");
	explain();
	cppcoding+="}\n";
	cout<<"正在编译……"<<endl; 
	clock_t start=clock(); 
	compile(cppcoding);
	clock_t end=clock();
	cout<<"编译完成! 编译共消耗了:"<<(double)(end - start)/ CLOCKS_PER_SEC<<"s"<<endl; 
} 
