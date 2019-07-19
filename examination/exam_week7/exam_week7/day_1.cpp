#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

#if 0
void phoneTranslate(string& str,map<char,int>& phoneM)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		str.erase(str.begin()+i);
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] < 65)
			continue;
		str[i] = phoneM[str[i]];
	}
}

int main()
{
	map<char, int> phoneM;
	phoneM['A'] = '2';
	phoneM['B'] = '2';
	phoneM['C'] = '2';
	
	phoneM['D'] = '3';
	phoneM['E'] = '3';
	phoneM['F'] = '3';

	phoneM['G'] = '4';
	phoneM['H'] = '4';
	phoneM['I'] = '4';

	phoneM['J'] = '5';
	phoneM['K'] = '5';
	phoneM['L'] = '5';

	phoneM['M'] = '6';
	phoneM['N'] = '6';
	phoneM['O'] = '6';

	phoneM['P'] = '7';
	phoneM['Q'] = '7';
	phoneM['R'] = '7';
	phoneM['S'] = '7';

	phoneM['T'] = '8';
	phoneM['U'] = '8';
	phoneM['V'] = '8';

	phoneM['W'] = '9';
	phoneM['X'] = '9';
	phoneM['Y'] = '9';
	phoneM['Z'] = '9';

	int n;
	while (cin >> n)
	{
		set <string> s;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			//getline(cin, str);
			phoneTranslate(str, phoneM);
			str.insert(str.begin() + 3, '-');
			s.insert(str);
		}
		auto it = s.begin();
		for (it; it != s.end(); it++)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}
#endif

#if 0
//求和：输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,
//使其和等于 m ,要求将其中所有的可能组合列出来
//某一大神写的
//链接：https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
//来源：牛客网

#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) {
	//if (beg>n) return;
	if (m == 0) {
		for (int i = 0; i<v.size(); i++) {
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++) {
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}
}
#endif

