#define _CRT_SECURE_NO_WARNINGS

/*
1.����֮���ת��/�����ڳ����д洢��ʽ
2.64/32λ�½ṹ���С
3.ָ���ַ������ָ�� 
4.%o �ĸ��int m=0123��n=123�����%o�Ľ��
5.����������ĸ�ʽ���Լ�ascii���Ӧ��
6.���������ĸ���
7.�������
8.������������﷨/����
9.�������õķ�ʽ���
10.�ݹ�ĵ��÷�ʽ�Լ�����
*/

//M*N���ŵ������⣬����֮��ľ��벻����2

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