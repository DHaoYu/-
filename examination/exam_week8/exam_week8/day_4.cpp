#define _CRT_SECURE_NO_WARNNINGS 1

// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#if 0
//发邮件
long long int Failrec(int n)//需要用到长整形，否则int存不下
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
		long long int count = Failrec(n);
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
void LIS(vector<int>& v)
{
	int sum = 0;
	int count = 1, pos = 0;
	for (size_t i = 0; i<v.size(); i++)
	{
		pos = i;
		for (size_t k = 1; k<v.size(); k++)
		{
			for (size_t j = i + k; j<v.size(); j++)
			{
				if (v[j]>v[pos])
				{
					count++;
					pos = j;
				}
			}
			if (count>sum)
				sum = count;
			count = 1;
			pos = i;
		}
	}
	cout << sum << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<int> v(n);
		for (size_t i = 0; i<n; i++)
			cin >> v[i];
		LIS(v);
	}
	return 0;
}
#endif

#if 0
void LIS(vector<int>& v)
{
	//动态规划
	vector<int> dp(v.size(), 1);
	int sum = 1;
	for (size_t i = 1; i<v.size(); i++)
	{
		for (size_t j = 0; j<i; j++)
		if (v[i]>v[j])
			dp[i] = max(dp[i], dp[j] + 1);
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<int> v(n);
		for (int i = 0; i<n; i++)
			cin >> v[i];
		LIS(v);
	}
	return 0;
}
#endif
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

#if 0
//Linux
void runShell(vector<string>& v)
{
	char* argv[32];
	for (size_t i = 0; i<v.size(); i++)
	{
		argv[i] = (char*)v[i].c_str();
	}
	execvp(v[0], argv[v.size()]);
}



void transStr(string& cmd)
{
	vector<string> v;
	size_t begin = 0;
	size_t end=0;
		while (end != string::npos)
		{
			end = cmd.find(' ');
			v.push_back(cmd.substr(begin, end - begin));
			cmd = cmd.substr(end + 1, cmd.size() - end - 1);
		}
		for (size_t i = 0; i < v.size(); i++)
			cout << v[i] << " ";
}
	int main()
	{
		string tip = "[minishell]$ ";
		//getchar();
		//fflush(stdin);
		string cmd;
		vector<string> vcmd;
		while (1)
		{
			cout << tip;
			getline(cin, cmd);
			transStr(cmd);
		}
		return 0;
	}

#endif