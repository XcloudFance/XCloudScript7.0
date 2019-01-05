#include<windows.h>
#include "stringbuilder.h"
#define formem(i) for(int mem=0;mem<i;mem++) 
#define fornum(i,j) for(int num=i,num<=j;num++)
string getfilepath()
{
	char ExePath[MAX_PATH];
	GetModuleFileName(NULL, ExePath, MAX_PATH);
	for(int i=strlen(ExePath)-1;i>0;i--)
	{
		//int node=0;
		if(ExePath[i]=='\\')
		break;
		ExePath[i]='\0';
	}
	string res=ExePath;
	return res;
}
inline int readint()
{
    register int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
inline void outf(Stringbuilder coding,string end="\n") 
{
	cout<<coding<<end;
}
inline void outf(int coding,string end="\n") 
{
	cout<<coding<<end;
}

inline void outf(double coding,string end="\n") 
{
	cout<<(double)coding<<end;
}

inline int sum(int a, ...){
    int *temp = &a, sum=0;
    ++temp;
    for (int i = 0; i < a; ++i)
        sum+=*temp++;
    return sum;
}



class runtime{
	clock_t begin;
	clock_t end;
	public:
	void start()
	{
		begin=clock();
	} 

	double finish()
	{
		this->end=clock();
		double a=(((double)this->end - this->begin)/ (CLOCKS_PER_SEC));
		return a;
	}
}; 
string str(int s)
{
	string res;
	while(s)
	{
		res+=s%10;
		s/=10;
	}
	return res;
}
string str(double num)
{
    char str[256];
    sprintf(str, "%lf", num);
    string result = str;
    return result;
}
string str(bool num)
{
	return num?"true":"false";
}
string str(Stringbuilder num)
{
	return num.tostr();
} 
