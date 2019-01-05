#include "stringbuilder.h" 
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	Stringbuilder s="print(1,,23)";
	if(s=="233")
	cout<<1;
	for (Stringbuilder i :s.split(","))
	{
		cout<<i<<endl;
	}
}
