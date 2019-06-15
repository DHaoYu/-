#define _CRT_SECURE_NO_WARNNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		n += (n / 2);
		cout << n / 3 << endl;
	}
	return  0;
}
#endif


#if 0
#include<string>

void Longsubstring(string& s1, string& s2)
{
	size_t count = 0;
	size_t max = 0;
	string str;
	if (s1.size()>s2.size())
		swap(s1, s2);
	for (size_t i = 0; i < s1.size(); i++)
	{
		for (size_t j = 0; j < s2.size(); j++)
		{
			size_t k = i;
			while (s2[j] == s1[k] && k<s1.size() && j<s2.size())
			{
				count++;
				k++;
				j++;
			}
			if (count>max)
			{
				str = s1.substr(i, count);
				max = count;
			}
			count = 0;
		}
	}
	cout << str << endl;
}

int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		Longsubstring(s1, s2);
	}

	return 0;
}
#endif