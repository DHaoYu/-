// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

#if 0
//¼ô»¨²¼Ìõ
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = 0, k = i;
			while (s[k] == t[j] && k < s.size())
			{
				++k; ++j;
			}
			if (j == t.size())
			{
				count++;
				i = k - 1;
			}
		}
		cout << count << endl;
	}
}
#endif

#if 0
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		while (s.find(t) != string::npos)
		{
			count++;
			s.erase(s.find(t), t.size());
		}
		cout << count << endl;
	}
}
#endif