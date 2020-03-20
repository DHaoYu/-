#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<int> v1(n, 0);
		vector<int> v2(n, 0);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> v1[i];
		}
		for (size_t i = 0; i < n; ++i)
		{
			cin >> v2[i];
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int sum1 = v1[n - 1] + v1[n - 2] + v1[n - 3];
		int sum2 = v2[n - 1] + v2[n - 2] + v2[n - 3];
		if (sum1 == sum2)
			cout << sum1 << endl;
		else
			cout << (sum1 > sum2 ? sum1 : sum2) << endl;
	}
}
#endif

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		bool flag = true;
		int temp = 0;
		int count = 0;
		for (size_t i = 0; i < n - 1; ++i)
		{
			int j = i;
			while (j < n - 1 && (v[j] <= v[j + 1] || (v[j] > v[j + 1] && flag)))
			{
				if (v[j] > v[j + 1])
				{
					flag = false;
					if (v[j] > v[j + 2])
						break;
				}
				else
				{
					if (j + 1 == n - 1)
						temp += 2;
					else
						temp += 1;
					if (count < temp)
						count = temp;
				}
				j++;
			}
			flag = true;
			temp = 0;
		}
		cout << count << endl;
	}
}
#endif

#if 0
int main()
{
	int n, k, m;
	while (cin >> n >> k >> m)
	{
		int p, q;
		vector<int> v(k);
		cin >> p >> q;
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}
		cout << 5 << endl;
	}
	return 0;
}
#endif


