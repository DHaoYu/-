#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

#if 0
void part_string(string& s1,size_t& i)
{
	string s2;
	i++;
	while (s1[i] != '"')
	{
		s2.push_back(s1[i]);
		i++;
	}
	i++;
	cout << s2 << endl;
}


int main()
{
	string s1,s2;
	getline(cin, s1);
	size_t i = 0;
	int count = 0;
	int count1 = 0;

	while (i < s1.size())
	{
		if (s1[i] == ' ')
			count++;
		i++;
	}
	cout << count + 1 << endl;
	i = 0;
	while (i <= s1.size())
	{
		if (s1[i] == '"')
		{
			part_string(s1, i);
			count++;
		}

		if (s1[i] != ' ')
			s2.push_back(s1[i]);
		else
		{
			cout << s2 << endl;
			s2.erase(s2.begin(),s2.end());
		}
		i++;
	}
	cout << s2 << endl;
	return 0;
}
#endif


