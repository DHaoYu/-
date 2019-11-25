#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
#if 0
int main(){
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No");//strcpy 会拷贝完字符串的同时加上\0
	if (strcmp(ccString1, ccString2) == 0)
		cout << ccString2;
	else
		cout << ccString1;
}
#endif
#if 0
int main()
{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	//reinterpret_cast强制类型转化符
	p1++;
	p = reinterpret_cast<char *>(p1);
	printf("result is %s\n", p);
}
#endif
#if 0
void replaceSpace(char *str, int length) {
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')

			strcat(&str[i], "\%20");
	}
	cout << str << endl;
}

int main()
{
	replaceSpace("hello world", 11);
}
#endif
#if 0
void Test(char& x)
{
	char y[14];
	cout << sizeof(y) << endl;
	cout << sizeof(x) << endl;
}

int main()
{
	char c[10];
	cout << sizeof(c) << endl;
	Test(c[1]);
}
#endif
#if 0
//计算日期到天数转换
#include<iostream>
#include<vector>
using namespace std;

bool IsLeapyear(int y)
{
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
	{
		return true;
	}
	return false;
}

int main()
{
	vector<int> md{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int y, m, d;
	while (cin >> y >> m >> d)
	{
		int sum = 0;
		if (m > 12 || m <= 0 || d <= 0)
		{
			cout << -1 << endl;
			return 0;
		}
		bool l = IsLeapyear(y);
		if (l == true && m > 2)
			sum += 1;
		for (int i = 0; i < m; i++)
		{
			sum += md[i];
		}
		if (l == true && md[m] + 1 < d)
		{
			cout << -1 << endl;
			return 0;
		}
		if (l == false && md[m] < d)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << sum + d << endl;
	}
	return 0;
}
#endif