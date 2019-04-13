#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int ,int ,int ):, , ,:" << this << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d):, , ,:" << this << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	//int& _r;
	//const int _a;
};

int main()
{
	Date d1(2019, 4, 10);
	Date d2(d1);
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int , int , int):, , ,:" << this << endl;
	}

	~Time()
	{
		cout << "~Time():" << this << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(0,0,0)
		//,_t()--->�����޲εĹ��캯��
	{
		cout << "Date(int , int , int ,): , , ,Time:" << this << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1(2019, 4, 10);
	return 0;
}
#endif

#if 0
class Date
{
public:
	explicit Date(int year)//explicit����������������ʽ��ת��
		:_year(year)
	{
		cout << "Date(int ,int ,int):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		//_year = year;
		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Date d(2019);
	Date d(2019);
	d = 2020;  //-->ͨ�����ι��캯��--->��ʱ����2020��ʽ��ת��ΪDate����
	//explicit�ڹ��캯���г��ֻ�������ʽ��ת��
	return 0;
}
#endif

#if 0
class Time

{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}

private:
	int _hour;
};

class Date
{
public:
	Date(int day, Time t)
	{
		_day = day;
	}

private:
	int _day;
	Time _t;
};


int main()
{
	//Date d1 = { 2, { 5 } };
	Date d(2, 5);//����Ƕ����ĳ�ʼ��Ҫ��
	return 0;
}
#endif


#if 0
//������ʲôʱ����Զ����ɹ��캯�����������캯����
//�ڱ������о��Լ���Ҫ������¾ͻ��Զ�����--->ʲôʱ����Ǳ�������Ҫ��ʱ��
//���ֳ�����
//1.Time������ȱʡ���캯����Date����û�и����κι��캯��


class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)//0,0,0Ϊȱʡֵ-->����ʵ�ε�ֵ
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int ,int ,int ):" << this << endl;
	}

	Time(Time& t)
	{}

	Time& operator=(const Time t)
	{
		return *this;
	}

	~Time()
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//Date(Date& d)
	//{}


private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	Date d2(d1);

	return 0;
}
#endif

