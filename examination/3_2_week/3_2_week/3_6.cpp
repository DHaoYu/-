// write your code here cpp
#include<iostream>
using namespace std;

#if 0
//年会抽奖
int main()
{
	//f(n) = (n-1)*(f(n-1)+f(n-2))
	long long ErrCount[21] = { 0, 0, 1 };
	long long SumCount[21] = { 0, 1, 2 };
	for (int i = 3; i <= 21; i++)
	{
		ErrCount[i] = (i - 1)*(ErrCount[i - 1] + ErrCount[i - 2]);
		SumCount[i] = i*SumCount[i - 1];
	}
	int n;
	while (cin >> n)
	{
		printf("%.2f%%\n", (100.0*ErrCount[n]) / SumCount[n]);
	}
	return 0;
}
#endif

#if 0
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		if (s1.find(s2) != -1)
		{
			int pos = s1.find(s2);
			if (pos == 0 && s1.size() != s2.size())
				cout << "Ignore" << endl;
			else if (pos == 0 && s1.size() == s2.size())
				cout << "Important!" << endl;
			else if (s1[pos - 1] == '"' && s1[pos + s2.size()] == '"')
				cout << "Ignore" << endl;
			else if (s1[pos - 1] == ',')
				cout << "Ignore" << endl;
			else
				cout << "Important!" << endl;
		}
		else
			cout << "Important!" << endl;
	}
	return 0;
}
#endif

#if 0

#include<iostream>
using namespace std;
int Cal_week(int year, int month, int day)
{
	int Week = 0;
	int y = 0, m = 0, d = 0, c = 0;
	if (month == 1 || month == 2)
	{
		c = (year - 1) / 100;
		y = (year - 1) % 100;
		m = month + 12;
		d = day;
	}
	else
	{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}
	Week = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
	Week = Week >= 0 ? (Week % 7) : (Week % 7 + 7);//iWeek为负时取模
	if (Week == 0)//星期日不作为一周的第一天
		Week = 7;
	return Week;
}
void Print_Date(int year, int month, int day)
{
	printf("%d-%02d-%02d\n", year, month, day);
}
void New_year(int year)
{
	Print_Date(year, 1, 1);
}
void Martin(int year)
{
	int month = 1;
	int day = 1;
	int Week = Cal_week(year, month, day);
	if (Week != 1)
	{
		day += 8 - Week;
	}
	day += 14;
	Print_Date(year, month, day);
}
void Presidential(int year)
{
	int month = 2;
	int day = 1;
	int Week = Cal_week(year, month, day);
	if (Week != 1)
	{
		day += 8 - Week;
	}
	day += 14;
	Print_Date(year, month, day);
}
void Memorial(int year)
{
	int month = 5;
	int day = 31;
	int Week = Cal_week(year, month, day);
	if (Week != 1)
	{
		day -= Week - 1;
	}
	Print_Date(year, month, day);
}
void National(int year)
{
	Print_Date(year, 7, 4);
}
void Labor(int year)
{
	int month = 9;
	int day = 1;
	int Week = Cal_week(year, month, day);
	if (Week != 1)
	{
		day += 8 - Week;
	}
	Print_Date(year, month, day);
}
void Thanksgiving(int year)
{
	int month = 11;
	int day = 1;
	int Week = Cal_week(year, month, day);
	if (Week != 4)
	{
		int arr[7] = { 3, 2, 1, 0, 6, 5, 4 };
		day += arr[Week - 1];
	}
	day += 21;
	if (day + 7 <= 30)
		day += 7;
	Print_Date(year, month, day);
}
void Christmas(int year)
{
	Print_Date(year, 12, 25);
}
void American_Holidays(int year)
{
	New_year(year);//1月1日：元旦
	Martin(year);//1月的第三个星期一：马丁·路德·金纪念日
	Presidential(year);//2月的第三个星期一：总统节
	Memorial(year);//5月的最后一个星期一：阵亡将士纪念日
	National(year);//7月4日：美国国庆
	Labor(year);//9月的第一个星期一：劳动节
	Thanksgiving(year);//11月的第四个星期四：感恩节
	Christmas(year);//12月25日：圣诞节
}
int main()
{
	int year;
	while (cin >> year)
		American_Holidays(year);
	return 0;
}
#endif