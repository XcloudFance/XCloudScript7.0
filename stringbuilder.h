#include<string>
#include<cstring>
#include<iostream>
#include<fstream> 
using namespace std;
class Stringbuilder{
	private:
	string content;
	public:
	int Length;
	int length()
	{
	return this->Length;	
	}
	Stringbuilder& operator =(const Stringbuilder& str)//��ֵ�����
    {
        if (this != &str)
        {
            this->content=str.content;
        }
        return *this;
    }
	char& operator [](const int index)
	{
		return content[index];
	} 
 	Stringbuilder& operator =(const string str)//��ֵ�����
    {
        if (this->content != str)
        {
            this->content=str;
            this->Length=str.length();
        }
        return *this;
    }
    Stringbuilder& operator =(const char str[])//��ֵ�����
    {
        if (this->content != str)
        {
            this->content=str;
            this->Length=strlen(str);
        }
        return *this;
    }
    friend istream& operator>>(istream &is, Stringbuilder &str)//����cin  ע����Ԫ����
	{
		char tem[1000];  //�򵥵�����һ���ڴ�
		is >> tem;
		str.content=tem;
		str.Length=strlen(tem);
		return is;
	}
	friend ostream& operator<<(ostream &os,  Stringbuilder &str)//����cout
	{
		os << str.content.data();
		return os;
	}
	const char* tostr()
	{
		return this->content.data();
	}
	
}; 
