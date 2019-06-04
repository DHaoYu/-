#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#if 0

int binInsert() {
	// write code here
	int n, m, j, i;
	cin >> n >> m >> j >> i;
	m = m << j;
	int sum=0;
	sum = pow(2, i + 1) - 1;

	m = m&sum;
	return m + n;
}

int main()
{
	cout<<binInsert();
	return 0;
}
#endif

int main()
{
	int n;
	cin >> n;
	n /= 2;
	int m = n;
	while (m)
	{
		m--;
		n++;
		int k = 0;
		for (k = 2; k<m; k++)
		if (m%k == 0 || n%k == 0)
			break;
		if (k == m)
		{
			cout << m << n << endl;
			return 0;
		}

	}

	return 0;
}