#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
//小易的升级之路
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	int n, num, lev;
	while (cin >> n >> lev)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			if (lev >= num)
				lev += num;
			else
				lev += gcd(num, lev);
		}
		cout << lev << endl;
	}
}
#endif

#if 0
//找出字符串中第一个只出现一次的字符(题面已经更新)
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				cout << str[i] << endl;
				break;
			}
			if (i == str.size()-1)
				cout << -1 << endl;
		}
	}
	return 0;
}
#endif