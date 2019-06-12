#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<stdio.h>
#if 0
int main()
{
	char* p = "abc";//不可被修改
	char* q = "abc123";
	*p = 'd';
	//while (*p = *q)//error
		printf("%c %c", *p, *q);
	return 0;
}


int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);//%d为int型输出，输出4个字节，但是longlong是8个字节
	return 0;
}
#endif

#if 0
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 2)
		cout << -1 << endl;
	else if (n % 2 != 0)
		cout << 2 << endl;
	else
	{
		if (n % 4 == 0)
			cout << 3 << endl;
		else
			cout << 4 << endl;
	}
	return 0;
}
#endif

#if 0
//实现两个长整数加法
#include<string>

void operator+(string& s1, string& s2)
{
	if (s1.size() < s2.size())
		swap(s1, s2);
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		int j = s2.size() - 1;
		if (j<0)
			break;
		char c = s1[i] + s2[j] - 48;
		if (c >= 58)
		{
			c -= 10;
			if (i == 0)
			{
				s1.insert(0, "1");
				i += 1;
				s1[i] = c;
				break;
			}
			if (j == 0)
			{
				s2.insert(0, "1");
				j += 1;
			}
		}
		s1[i] = c;
		s2.pop_back();
	}
	cout << s1 << endl;
}

int main()
{
	string s1, s2;
	while (cin>>s1>>s2)
	{
		s1 + s2;
	}

	return 0;
}
#endif