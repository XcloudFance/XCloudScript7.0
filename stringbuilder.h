#include<string>
#include<cstring>
#include<iostream>
#include<fstream> 
#include<vector>
using namespace std;

class Stringbuilder{
	private:
	string content;
	public:
	int Length;
	int length()
	{
	return this->content.length();	
	}
	Stringbuilder(const char x[])
	{
		content=x;
	} 
	Stringbuilder()
	{
		
	}
	Stringbuilder(int n)
	{
		while(n)
		{
			content+=n%10;
			n/=10;
		}
	}
	Stringbuilder(string s)
	{
		content=s;
	}
	Stringbuilder& operator =(const Stringbuilder& str)//赋值运算符
    {
        if (this != &str)
        {
            this->content=str.content;
        }
        return *this;
    }
 	
    Stringbuilder& operator +(const Stringbuilder& str)//赋值运算符
    {
        if (this != &str)
        {
            this->content+=str.content;
        }
        return *this;
    }
    Stringbuilder& operator +(const char str[])//赋值运算符
    {
        
            this->content+=str;
        
        return *this;
    }
    int find(Stringbuilder str)
    {
    	return this->content.find(str.tostr());
    }
    int rfind(Stringbuilder str)
    {
    	return this->content.rfind(str.tostr());
    }
    Stringbuilder substr(int begin,int end)
    {
    	if(begin>end)
    	return this->content.substr(begin,end); 
    	else 
    	return this->content.substr(begin,end-begin);
    }
    inline vector<Stringbuilder> split(Stringbuilder pattern)
	{
	    char * strc = new char[this->length()+1];
	    strcpy(strc, this->tostr());
	    vector<Stringbuilder> resultVec;
	    char* tmpStr = strtok(strc, pattern.tostr());
	    while (tmpStr != NULL)
	    {
	        resultVec.push_back(tmpStr);
	        tmpStr = strtok(NULL, pattern.tostr());
	    }
	
	    delete[] strc;
	
	    return resultVec;
	}
    Stringbuilder substr(Stringbuilder str,Stringbuilder str1)
    {
		//cout<<str<<str1;    
    	return this->substr(this->find(str)+str.length(),this->find(str1));
    }
    bool operator >( Stringbuilder str)//赋值运算符
    {
            return this->content>str.content;
    }
     bool operator <( Stringbuilder str)//赋值运算符
    {
            return this->content<str.content;
    }
    inline bool operator ==( Stringbuilder str)//赋值运算符
    {
            return this->content==str.content;
    }
     bool operator >=( Stringbuilder str)//赋值运算符
    {
            return this->content>=str.content;
    }
     bool operator <=( Stringbuilder str)//赋值运算符
    {
            return this->content<=str.content;
    }
     bool operator !=( Stringbuilder str)//赋值运算符
    {
            return this->content!=str.content;
    }
	char& operator [](const int index)
	{
		return content[index];
	} 
 	Stringbuilder& operator =(const string str)//赋值运算符
    {
        if (this->content != str)
        {
            this->content=str;
            this->Length=str.length();
        }
        return *this;
    }
    Stringbuilder& operator =(const char str[])//赋值运算符
    {
        if (this->content != str)
        {
            this->content=str;
            this->Length=strlen(str);
        }
        return *this;
    }
    friend istream& operator>>(istream &is, Stringbuilder &str)//重载cin  注意友元函数
	{
		char tem[9000];  //简单的申请一块内存
		is >> tem;
		str.content=tem;
		str.Length=strlen(tem);
		return is;
	}
	friend ostream& operator<<(ostream &os,  const Stringbuilder &str)//重载cout
	{
		os << str.content;
		return os;
	}
	const char* tostr()
	{
		return this->content.data();
	}
	
	
}; 
Stringbuilder make_Stringbuilder(const char s[])
{
	Stringbuilder tmp=s;
	return tmp;
}
