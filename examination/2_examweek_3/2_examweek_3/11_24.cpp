#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;
#if 0
int main()
{
	char p[] = "abc";
	char q[] = "abc123";
	while (*p = *q)
		printf("%c %c", *(p), *(q));
}
#endif
#if 0
//iNOC产品部-杨辉三角的变形
#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if(n <= 2)
			cout<<-1<<endl;
		else if((n-2) % 4 == 0)
			cout<<4<<endl;
		else if(n % 2 == 1)
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
}
#endif


#if 0
#include<string>
#include<iostream>
using namespace std;
//超长正整数相加
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		while (s1.size() < s2.size())//和最长数补齐
			s1 = '0' + s1;
		while (s2.size() < s1.size())
			s2 = '0' + s2;
		for (int i = s1.size() - 1; i > 0; i--)
		{
			s1[i] += s2[i] - '0';
			if (s1[i] > '9')
			{
				s1[i - 1] += 1;
				s1[i] -= 10;
			}
		}
		s1[0] += s2[0] - '0';
		if (s1[0] > '9')
		{
			s1[0] -= 10;
			s1 = '1' + s1;
		}
		cout << s1 << endl;
	}
}
#endif