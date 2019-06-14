#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;


#if 0
//递归求fib
int fib(int n)
{
	if (n == 0)
	{
		return 1;
	}

	if (n == 1)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);

}

void Sum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += fib(i);
	}
	cout << sum << endl;
}

int main()
{
	int n = 5;
	cout << fib(n) << endl;
	Sum(n);
	return 0;
}
#endif

#if 0
//计算兔子数量
int main()
{
	int m = 0;
	while (cin >> m)
	{
		int a = 1, b = 0, c = 0;
		while (--m)
		{
			c = c + b;
			b = a;
			a = c;
			//cout << a << '\t' << b << '\t' << c << endl;
		}
		cout << a + b + c << endl;
	}
	return 0;
}
#endif





