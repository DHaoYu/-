#define _CRT_SECURE_NO_WARNINGS

/*
1.进制之间的转换/进制在程序中存储方式
2.64/32位下结构体大小
3.指向字符数组的指针 
4.%o 的概念，int m=0123，n=123，输出%o的结果
5.输入输出流的格式，以及ascii码的应用
6.内联函数的概念
7.深拷贝概念
8.重载运算符的语法/概念
9.函数调用的方式结果
10.递归的调用方式以及出口
*/

//M*N表格放蛋糕问题，两者之间的距离不等于2

#include<iostream>
using namespace std;

#if 0
int main()
{
	int W, H;
	cin >> H >> W;
	int count = 0;
	int** arr = new int*[H];
	for (int i = 0; i < W; i++)
	{
		arr[i] = new int[W];
	}
	for (int i = 0; i<H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if ((i - 2<0 && j - 2<0))
			{
				count++;
				arr[i][j] = 1;
			}
			if ((i - 2 >= 0 && (arr[i - 2][j] != 1))
				||(j - 2 >= 0 && (arr[i][j - 2] != 1)))
			{
				arr[i][j] = 1;
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
#include<cstdlib>
#include<math.h>
#include<string>
using namespace std;

int StrToInt(string str) {
	int value = 0;
	for (size_t i = 0; i<str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] <= '0' || str[i] >= '9')
			return value;
	}
	for (size_t i = 0; i<str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		value += (str[i] - 48)*pow(10, str.size() - i - 1);
	}
	if (str[0] == '-')
		return 0 - value;
	return value;
}

int main()
{
	string s("+12334345");
	cout<<StrToInt(s);
	return 0;
}
#endif