#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


#if 0
//�������������������������Ĺ������ȣ�������

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

//��һ���������еĶ�����λ������1�ĸ���
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