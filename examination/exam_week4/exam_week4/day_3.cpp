#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

#if 0
int main()
{
	int T, n, k;
	int i = 0;
	vector<int> V, v1, v2;
	cin >> T;
	while (T--)
	{
		i = 0;
		cin >> n >> k;
		V.resize(2 * n);
		v1.resize(n);
		v2.resize(n);
		while (i < 2 * n)
		{
			cin >> V[i];
			i++;
		}

		while (k--)
		{
			for (i = 0; i < n; i++)
			{
				v1[i] = V[i];
				v2[i] = V[i + n];
			}
			int j = 0;
			for (i = 0; i < n; i++)
			{
				V[j++] = v1[i];
				V[j++] = v2[i];
			}
		}
		for (auto e : V)
		{
			cout << e << " ";
		}
		cout<<endl;
	}

	return 0;
}
#endif

#if 0
#include<string>

int main()
{
	string com;
	int n;
	int i = 1;
	int k = 0;
	while (cin >> n)
	{
		fflush(stdin);
		getline(cin, com);
		while (com[k])
		{
			if (com[k] == 'U')
			{
				i -= 1;
				if (i == 0)
					i = n;
			}
			if (com[k] == 'D')
			{
				i += 1;
				if (i == n + 1)
					i = 1;
			}
			k++;
		}
		k = 0;
		if (n <= 4)
		{
			while (n--)
				cout << n << " ";
			cout << endl;
		}
		else
		{
			int j = i;
			while (j + 4 > n+1)
				j--;
				cout << j++ << " ";
				cout << j++ << " ";
				cout << j++ << " ";
				cout << j++ << " ";
			cout << endl;
		}
		cout << i << endl;
		i = 1;
	}
}
#endif
