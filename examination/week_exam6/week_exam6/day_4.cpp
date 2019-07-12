#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
void ListRec(int n, vector<string>& v)
{
	for (int i = 0; i<n; i++)
	{
		if ((v[i].find(',') != string::npos)||( v[i].find(' ')!=string::npos))
		{
			v[i].insert(v[i].begin(), '"');
			v[i].insert(v[i].end(), '"');
		}
		cout << v[i];
		if (i<n - 1)
			cout << ",";
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		fflush(stdin);
		vector<string> v(n);
		for (int i = 0; i<n; i++)
		{
			getline(cin, v[i]);
		}
		ListRec(n, v);
	}

	return 0;
}
#endif

#if 0
//养兔子问题
//1
int main()
{
	long long n;
	long long child = 1;
	long long adult = 0;
	long long i = 0;
	long long temp;

	while (cin >> n)
	{
		i = 0;
		child = 1;
		adult = 0;
		while (++i <= n)
		{
			temp = child;//temp变量中间量
			child = adult;//成年兔继续生小兔
			adult += temp;//当天的小兔变成成年兔
		}

		cout << adult + child << endl;

	}
}

//2 养兔子  存数组
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		long long arr[91] = { 1, 1 };
		for (int i = 2; i<91; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}

		cout << arr[n] << endl;
	}

	return 0;
}
#endif