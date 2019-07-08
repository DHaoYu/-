#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
using namespace std;

//破译密码
#if 0
void MyDecode(string& str)
{
	for (size_t i = 0; i<str.size(); i++)
	{
		if (str[i] <= 69 && str[i] != ' ')
		{
			str[i] += 21;
		}
		else if (str[i] == ' ')
			str[i];
		else
			str[i] -= 5;
	}
	cout << str << endl;
}



int main()
{
	string str;
	while (getline(cin, str))
		MyDecode(str);
	return 0;
}
#endif

#if 0
//计算因子个数
#include<set>

void DivCount(int& n)
{
	int i = 2;
	set<int> v;//利用set的不重复性，存储不重复因子
	while (n != 1)
	{
		if (n%i == 0)
		{
			n /= i;
			v.insert(i);
			i = 2;
		}
		else
			i++;
	}
	cout << v.size() << endl;//输出size的大小即为因子个数
}

int main()
{
	int n;
	while (cin >> n)
		DivCount(n);
	return 0;
}
#endif
