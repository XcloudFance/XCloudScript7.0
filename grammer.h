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

