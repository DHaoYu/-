#define _CRT_SECURE_NO_WARNINGS

#if 0 
//求字符串中，最长数字的长度并将其输出
#include<iostream>
#include<string>

using namespace std;

void LongestNumString(string& s)
{
	int length = 0;
	int j = 0;
	string sout;
	for (int i = 0; i<s.size(); i++)
	{
		j = i;
		while (s[i] >= '0' && s[i] <= '9' && i<s.size())
		{
			i++;
		}
		if (i - j>length)
		{
			length = i - j;
			string s1(s.begin() + j, s.begin() + i);
			//    sout.append(s.begin()+j-1,s.begin()+i-1);
			sout.resize(s1.size());
			for (int ii = 0; ii<s1.size(); ii++)
			{
				sout[ii] = s1[ii];
			}
		}
	}
	for (int i = 0; i<sout.size(); i++)
	{
		cout << sout[i];
	}
}


int main()
{
	string s;
	getline(cin, s);
	LongestNumString(s);

	return 0;
}
#endif

#if 0
//求在一个数组中，出现频数最高的元素，并输出
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Max_Frequency(vector<int>& v)
{
	int j = 0;
	int max = 0;
	int max_num;
	sort(v.begin(), v.end());

	for (int i = 0; i<v.size(); i++)
	{
		j = i;
		while (v[i] == v[i + 1])
		{
			i++;
		}
		if (i - j + 1>max)
		{
			max = i - j + 1;
			max_num = v[j];
		}
	}
	if (max >= v.size() / 2)
		cout << max_num << endl;
}

int main()
{
	int a;
	int n = 101;
	int x;
	vector<int> v;
	while (cin >> a)
	{
		x = cin.get();
		if (a == '\n')
			break;
		v.push_back(a);
	}
	Max_Frequency(v);
	return 0;
}
#endif

