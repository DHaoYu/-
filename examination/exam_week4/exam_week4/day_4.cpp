#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<vector>
using namespace std;

#if 0
void GCD(int& a, int& b)
{
	for (int i = a; i > 0; i--)
	{
		if (b%i == 0 && a%i == 0)
		{
			a += i;
			return;
		}
	}
}
#endif

#if 0
void GCD(int& a, int& b)//Õ·×ªÏà³ý·¨
{
	int temp = a;
	while (temp%b != 0)
	{
		int left = temp%b;
		temp = b;
		b = left;
	}
	a += b;
}

int main()
{
	int a,n;

	while (cin >> n >> a)
	{
		vector<int> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			if (a >= b[i])
				a += b[i];
			else
			{
				GCD(a, b[i]);
			}
		}
		cout << a << endl;
	}
	return 0;
}
#endif

#if 0
#include<string>

void strOnly(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		for (size_t j = 0; j < str.size(); j++)
		{
			if (j == i)
				j++;
			if (str[i] == str[j])
				break;
			if (j >= str.size() - 1 && str[i] != str[j])
			{
				cout << str[i] << endl;
				return;
			}
		}
	}
	cout << "-1" << endl;
}


int main()
{
	string str;
	while (getline(cin, str))
	{
		strOnly(str);
	}
	return 0;
}
#endif