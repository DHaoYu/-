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
		//,_t()--->调用无参的构造函数
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
	explicit Date(int year)//explicit会抑制数据类型隐式的转化
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
	d = 2020;  //-->通过单参构造函数--->临时对象（2020隐式的转化为Date对象）
	//explicit在构造函数中出现会抑制隐式的转换
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
	Date d(2, 5);//类中嵌套类的初始化要求
	return 0;
}
#endif


#if 0
//编译器什么时候会自动生成构造函数，拷贝构造函数等
//在编译器感觉自己需要的情况下就会自动生成--->什么时候才是编译器需要的时候
//四种场景：
//1.Time类中有缺省构造函数，Date类中没有给出任何构造函数


class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)//0,0,0为缺省值-->代替实参的值
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

