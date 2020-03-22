#include<iostream>
using namespace std;
#if 0
int Func1()
{
	int a = 1200000;
	int i = 2, count = 0;
	while (i <= a)
	{
		if (a % i == 0)
			count++;
		i++;
	}
	return count;
}
#include<string>
#include<sstream>
int Func2()
{
	int a = 0;
	for (int i = 0; i < 2021; i++)
	{
		stringstream s;
		s << i;
		string str = s.str();
		if (str.find('9') != string::npos)
			a++;
	}
	return a;
}

void StrtoInt(string& str)
{
	stringstream ss;
	ss << str;
	//int num = ss.get();
	int num;
	ss >> num;
	cout << num * 2 << endl;
}

void InttoStr(int num)
{
	stringstream ss;
	ss << num;
	string s;
	ss >> s;
	s.append("that is int to string");
	cout << s << endl;
}

void StrJoin()
{
	string str1 = "hello ";
	string str2 = "world!";
	stringstream ss;
	ss << str1 << str2;
	cout << ss.str() << endl;
}

void StrSplit()
{
	string str = "hello world !";
	stringstream ss;
	ss << str;
	string s1, s2, s3;
	ss >> s1 >> s2 >> s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << ss.str() << endl;
}

int main()
{
	//cout << 15 * 1024 + 0.125 * 1024 << endl;
	//cout << Func1() << endl;
	//cout << Func2() << endl;
	//string s = "456";
	//StrtoInt(s);
	//int num = 100;
	//InttoStr(num);
	//StrJoin();
	StrSplit();
}
#endif

#if 0
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		vector<long> v;
		long long a = 0;
		int pos = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == '*' || i == s.size()-1)
			{
				if (i == s.size() - 1)
					i++;
				string str = s.substr(pos, i - pos);
				pos = i + 1;
				stringstream ss;
				ss << str;
				ss >> a;
				v.push_back(a);
			}
		}
		long long sum = 1;
		for (size_t i = 0; i < v.size(); ++i)
		{
			sum *= v[i];
		}
		cout << sum << endl;
	}
	return 0;
}

// 字符串乘法  "123*456*789"  进行乘法运算
// 硬币兑换   有面值1，4，5三种硬币，给出一个值如（21）如何进行兑换使其硬币数量最小
// 路径问题， 给出起点（多个），终点（一个），最后打印出所有能到达终点的路径点
#endif