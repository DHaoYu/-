#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

#if 0
//矩阵幂运算，计算首位的值的后四位

int main()//error 不会写啊，例子看不懂，题目也看不懂
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		int sum = 0;
		while (n--)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
				sum += v[i];
			}
			sum = sum*v[0];
		}
		cout << sum << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>
//输出数据的树根
//仅限于int能够存储的数据大小
void Add(int& num)
{
	int sum = num;
	int temp = 0;

	if (sum < 10)
		cout << sum << endl;
	else
	{
		while (sum > 0)
		{
			temp += sum % 10;
			sum /= 10;
		}
		Add(temp);
	}
}


int main()
{
	int num;
	while (cin>>num)
	{
		Add(num);
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
//将string代替int ，可以扩大范围存储
int main()
{
	string s;
	while (cin >> s) {
		int sum = 0;
		for (int i = 0; i < s.size(); ++i) {
			sum += s[i] - 48;
		}
		while (sum > 9) {
			int c = 0;
			while (sum > 0) {
				c += sum % 10;
				sum /= 10;
			}
			sum = c;
		}
		cout << sum << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>
int main()
{
	string str;
	while (cin >> str)
	{
		int sum = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			sum += str[i] - 48;
		}
		while (sum > 9)
		{
			int num = 0;
			while (sum > 0)
			{
				num += sum % 10;
				sum /= 10;
			}
			sum = num;
		}

		cout << sum << endl;
	}
	return 0;
}
#endif