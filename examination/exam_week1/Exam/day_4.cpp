#define _CRT_SECURE_NO_WARNINGS

/*
1.����ָ�����飬ָ����ָ������鲢�ҷ���ֵΪT����
2.ָ�������ָ��/ָ������/ָ�������ָ��
3.쳲��������еݹ�����ļ��㷽��
4.ָ��������ǿ��ת��/ָ��ļӼ�����
5.���������㣬bit���߼�����
6.����Ա����������ֵ����
7.���麯�����е��÷�
8.thisָ���ʹ�÷���
9.��������Ĭ�ϳ�Ա�������������캯����
10.��������̳к����ĵ��ô����Լ�����ģ��
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
//���Ƶ�ת��----����Ӧ����ô�����
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