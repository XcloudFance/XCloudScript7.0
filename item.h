//item����ΪXCS�ٷ�����
//StringbuilderΪXCS�ٷ��ַ���
//Biginterger/int128ΪXCS-gmp��ģ��
//int256 ΪXCS-lua�ĸ������������߾��ȣ�ת��������stringbuilder�洢Ϊ���� 
//double256 ΪXCS-lua�ĸ������㸡���͸߾��ȣ�ת��������Stringbuilder�洢Ϊ����
#include<vector>
#include<algorithm>
template <typename T> 
class item
{
	vector<T> content;
	inline void append(T s)
	{
		content.push_back(s);
	}
	inline void push(T s)
	{
		content.push_back(s);
	} 
	inline void join(T s)
	{
		content.push_back(s);
	}
	inline void sort()
	{
		
			sort(content.begin(),content.end());
		
	}
} 
