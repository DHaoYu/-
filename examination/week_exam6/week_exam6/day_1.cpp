#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<stdio.h>
using namespace std;

#if 0
// write your code here cpp
class Date
{
public:
	friend void operator<<(ostream& _cout, Date& d);
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

void operator<<(ostream& _cout, Date& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}

int WeekToDay(int y, int m, int c, int w, bool B)
{
	//�����������µڼ������ڼ����Լ��������ǵ������������
	int d, week, i;
	if (m == 1){ m = 13; y--; }//��ʽҪ��1�¡�2��ҪתΪ��һ��13��14��
	if (m == 2){ m = 14; y--; }
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--)){//B������/����
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//���չ�ʽ
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}

int main()
{
	int y;
	while (cin >> y)
	{
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//����
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
		//cout << Date(year, 01, 01);
		//cout << Date(year, 1, WeekToDay(year, 1, 3, 1, 1));
	}

	return 0;
}
#endif

#if 0
int main()//����д����ţ����������ʱ�临�Ӷȹ���
{
	int n;
	int i = 2;
	bool b = 0;
	while (cin >> n)
	{
		while (n != 1)
		{
			if (n%i == 0)
			{
				if (b)
					cout << " * ";
				n /= i;
				cout << i;
				i = 2;
				b = 1;
			}
			i++;
		}
	}
	return 0;
}
#endif
