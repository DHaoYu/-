#define _CRT_SECURE_NO_WARNINGS

/*
1.函数指针数组，指向函数指针的数组并且返回值为T类型
2.指向数组的指针/指针数组/指向数组的指针
3.斐波那契数列递归次数的计算方法
4.指针与类型强制转化/指针的加减运算
5.二进制运算，bit、逻辑运算
6.常成员函数，返回值类型
7.纯虚函数类中的用法
8.this指针的使用方法
9.类中六个默认成员函数（拷贝构造函数）
10.菱形虚拟继承函数的调用次序以及函数模型
*/

#include<iostream>
using namespace std;

#if 0
int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	int A, B, C;
	A = (arr[0] + arr[2]) / 2;
	B = A - arr[0];
	C = arr[3] - B;
	if ((arr[0] + arr[2]) % 2 == 0 && A >= 0 && B >= 0 && C >= 0)
		cout << A << " " << B << " " << C << endl;
	else
		cout << "No" << endl;

	return 0;
}
#endif

#if 0
//进制的转化----负数应该怎么解决？
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int M, N;
	int n, devn;
	cin >> M;
	cin >> N;
	string s;
	while (M / N != 0)
	{
		n = M / N;
		devn = M%N;
		M = n;
		if (devn >= 10)
		{
			s.push_back('A' + devn - 10);
		}
		else
			s.push_back('0'+ devn);
	}
	if (n >= 10)
	{
		s.push_back('A' + n - 10);
	}
	else
		s.push_back('0' + n);

	reverse(s.begin(),s.end());
	cout << s << endl;
	return 0;
}
#endif