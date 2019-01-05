//item容器为XCS官方容器
//Stringbuilder为XCS官方字符串
//Biginterger/int128为XCS-gmp的模板
//int256 为XCS-lua的辅助计算整数高精度，转换后结果由stringbuilder存储为核心 
//double256 为XCS-lua的辅助计算浮点型高精度，转换后结果由Stringbuilder存储为核心
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
