#define _CRT_SECURE_NO_WARNNINGS 1

#include<map>
#include<iostream>
using namespace std;

#if 0
//�Ա�����
int main()
{
	int y1, y2, m1, m2, d1, d2;
	int norM[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int money = 0;
	while (cin >> y1 >> m1 >> d1)
	{
		cin >> y2 >> m2 >> d2;
		for (int year = y1; year <= y2 - 1; year++)
		{
			if ((year%4==0 && year%100!=0)  || ( year%400 == 0))

				money += 580;
			else
				money += 579;
		}
		if (y1 == y2)
		if ((year%4==0 && year%100!=0)  || ( year%400 == 0))

			money += 1;
		int temp = 0;
		for (int month = 0; month < m1 - 1; month++)//��ȥ��ӵĲ���
		{
			if	(month == 0 || month == 3 || month == 5 || month == 7 || month == 8 || month == 9 || month == 11)//month��0���±꿪ʼ
				temp += norM[month] * 2;
			else
				temp += norM[month];
		}
		int m = m1 - 1;
		if (m == 0 || m == 3 || m == 5 || m == 7 || m == 8 || m == 9 || m == 11)
			temp += (d1 - 1) * 2;//����Ҳ������Ǯ�ģ�������Ҫ��ȥ
		else
			temp += d1 - 1;
		money -= temp;
		temp = 0;
		for (int month = 0; month < m2 - 1; month++)//�����ټӵĲ���
		{
			if (month == 0 || month == 3 || month == 5 || month == 7 || month == 8 || month == 9 || month == 11)//month��0���±꿪ʼ
				temp += norM[month] * 2;
			else
				temp += norM[month];
		}
		m = m2 - 1;
		if (m == 0 || m == 3 || m == 5 || m == 7 || m == 8 || m == 9 || m == 11)
			temp += d2 * 2;
		else
			temp += d2;//��������Ҫ�������һ���
		money += temp;
		cout << money << endl;
	}
	return 0;
}
#endif

#if 0
#include<iomanip>
//쳲�������β

/*int main()
{
	long f[100001] = { 1, 2 };
	for (int i = 2; i<100000; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 1000000;
	}
	*/
int main()
{
	long arr[10001] = { 1, 2 };
	int n;
	for (int i = 2; i <= 100000; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
	//while (cin >> n)//��д��
	//{
	//	cout << arr[n-1] << endl;
	//}
	while (cin >> n)//���ϵ�
	{
		if (n<31)
			cout << arr[n - 1] << endl;
		else
			cout << setw(6) << setfill('0') << arr[n - 1] << endl;

	}
}
#endif
