#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
//ÂæÍÕÃüÃû·¨
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

void CamelCase(string& str)
{
	size_t pos = 0;
	while (1)
	{
		pos = str.find('_');
		if (pos == string::npos)
			break;
		str[pos + 1] -= 32;
		str.erase(pos,1);
	}
	cout << str << endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		CamelCase(str);
	}
	return 0;
}
#endif

#if 0
//µ¥´Êµ¹ÅÅ
#include<iostream>
#include<string>
using namespace std;

void InvertedWord(string& str)
{
	size_t pos = str.size();
	size_t end = pos;
	while (pos != string::npos)
	{
		pos = str.rfind(' ',pos-1);
		cout << str.substr(pos+1, end-pos-1)<<" ";
		end = pos;
	}
	cout << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		InvertedWord(str);
	}
	return 0;
}
#endif
