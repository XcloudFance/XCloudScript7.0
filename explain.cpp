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
	cout<<"ǰ����ʾ������XCS�ļ��ټ��𣬿��ܻ����runtime���޷���ȷ��ʱ�����!"<<endl; 
	ios::sync_with_stdio(false);cin.tie(0);//cout.tie(0);
	outf("233");
	explain();
	cppcoding+="}\n";
	cout<<"���ڱ��롭��"<<endl; 
	clock_t start=clock(); 
	compile(cppcoding);
	clock_t end=clock();
	cout<<"�������! ���빲������:"<<(double)(end - start)/ CLOCKS_PER_SEC<<"s"<<endl; 
} 
