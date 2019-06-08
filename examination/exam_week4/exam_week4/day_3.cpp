#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
int main()
{
	int a = 10;
	int b = 20;
	a = a - b;
	b = a + b;
	a = b - a;
	cout << a << " " << b << endl;
	return 0;
}
#endif 

#if 0
int main()
{
	double a = 0.0000;
	if (a == 0.0)
		printf("yes");
	int i = 3;
	printf("%d %d", ++i, ++i);//先将++i全部计算完成之后在进行打印
	return 0;
}
#endif


#if 0
int main()
{
	int n;
	int sum = 0;
	int count = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= (i/2)+1; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		if (sum == i)
		{
			count++;
		}
	}
	cout << count << endl;
	return -1;
}
#endif
#if 0
#include<string>

int main()
{
	string str;
	getline(cin, str);
	size_t pos = str.find('-');
	if (str.find("joker JOKER")!=-1)
		cout << "joker JOKER" << endl;
	else if (pos)
	{
		string s1, s2;
		s1 = str.substr(0, pos);
		s2 = str.substr(pos + 1);
		string line = "345678910JQKA2joker JOKER";
		if (s1[0] == '2')
			s1[0] += 'A';
		if (s2[0] == '2')
			s2[0] += 'A';
		if (s1.size() == s2.size())
		if (s1[0] > s2[0])
			cout << s1 << endl;
		else
			cout << s2 << endl;
		else if (s1.size() == 7)
			cout << s1 << endl;
		else
			cout << s2 << endl;

	}
	else
		cout << "ERROR" << endl;
	return 0;
}
#endif   