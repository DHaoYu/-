#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
//两种排序方法
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Isdict(vector<string>& vs)
{
	for (int i = 0; i < vs.size() - 1; i++)
	if (vs[i] > vs[i + 1])
		return false;
	return true;
}

bool Issize(vector<string>& vs)
{
	for (int i = 0; i < vs.size() - 1; i++)
	if (vs[i].size() > vs[i + 1].size())
		return false;
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; i++)
		getline(cin, vs[i]);
	if (Isdict(vs))
		if (Issize(vs))
			cout << "both" << endl;
		else
			cout << "lexicographically" << endl;
	else
	if (Issize(vs))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}
#endif

#if 0
//求最小公倍数
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int i = x;
	while (i--)
	{
		if (x % i == 0 && y % i == 0)
			x /= i;
	}
	cout << x * y << endl;
}
#endif
