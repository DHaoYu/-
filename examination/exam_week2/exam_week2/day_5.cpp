#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


#if 0
//无穷大满二叉树，求出两个结点的公共祖先，并返回

int getLCA(int a, int b) {
	// write code here
	while (a != b)
	{
		if (a>b)
			a /= 2;
		else
			b /= 2;
		if (a == b)
			return a;
	}
	return a;
}
#endif

//求一个整形数中的二进制位中连续1的个数
int main()
{
	int a;
	int count = 0;
	int max = 0;
	cin >> a;
	while (a != 0)
	{
		if (a % 2 == 1)
			count++;
		a = a >> 1;
		if (max <count && a % 2 == 0)
		{
			max = count;
			count = 0;
		}
	}
	cout << max << endl;
	return 0;
}