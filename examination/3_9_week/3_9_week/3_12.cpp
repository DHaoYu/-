
#if 0
//发邮件   错排问题
//两种解法  递归 和 迭代
// write your code here cpp
#include<iostream>
using namespace std;

long long arr[21] = { 0, 0, 1 };

int main()
{
	for (int i = 3; i < 21; ++i)  //迭代
	{
		arr[i] = (i - 1)*(arr[i - 1] + arr[i - 2]);
	}
	int n;
	while (cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}

//递归思想，第n个收件人可以递归到n-1个收件人与n-2个收件人之和
#include<iostream>
using namespace std;

long int Failrec(int n)   //din个人的错误概率 == n-1 倍的 n-1人的概率+ n-2个人的概率 
{
	if (n<2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << Failrec(n) << endl;
	}
	return 0;
}
#endif

#if 0
//最长上升子序列问题
#include<iostream>
#include<vector>
using namespace std;

void MLC(vector<int>& v)
{
	vector<int> dp(v.size(), 1);
	int count = 1;
	for (size_t i = 1; i < v.size(); ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		count = max(count, dp[i]);
	}
	cout << count << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (size_t i = 0; i < n; ++i)
			cin >> v[i];
		MLC(v);
	}
}
#endif