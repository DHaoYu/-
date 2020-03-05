#if 0
// write your code here cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int a = 1;
		int b = 0;
		int c = 0;
		while (n--)
		{
			c = a + b;
			c %= 1000000;
			b = a;
			a = c;
		}
		if (n > 37)
			cout << setfill('0') << setw(6) << c << endl;
		else
			cout << c << endl;
	}
}
#endif