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
string judge1(string line)//�жϵ�ǰ���д����Ƿ�Ϊ��ֵ 
{
	
}
string judge2(string line)//�жϵ�ǰ���д����Ƿ�Ϊ���� 
{
	
} 
string judge3(string line)//�жϸ�ֵ�ź���ı������� 
{
	
} 
