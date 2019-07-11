#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<string>
using namespace std;

#if 0
void CutStr(string& s1, string& s2)
{
	int count = 0;
	for (size_t i = 0; i<s1.size(); i++)
	{
		size_t index = i;
		for (size_t j = 0; j<s2.size(); j++)
		{
			if (s1[index] != s2[j])
				break;
			else
				index++;
			if (s1[index - 1] == s2[s2.size() - 1] && j == s2.size() - 1)
			{
				count++;
				i = index - 1;
			}
		}
	}
	cout << count << endl;
}

//int main()
//{
//	string s1;
//	string s2;
//	while (getline(cin, s1))
//	{
//		getline(cin, s2);
//		CutStr(s1, s2);
//	}
//	return 0;
//}

int main()//大佬做的 充分利用string容器，进行解题，值得我学习！
{
	string s, t;
	while (cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)//find应用 ！！！
		{
			pos += t.size();
			++res;
		}

		cout << res << endl;
	}

	return 0;
}
#endif

#if 0
int main()
{
	int from, to;
	int sum = 0;//需要用大数表示，4个字节装不下
	while (cin >> from >> to)
	{
		int arr[81] = { 1, 1 };//与上同理
		for (int i = 2; i<81; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		for (int i = from - 1; i<to; i++)
			sum += arr[i];
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
#endif
