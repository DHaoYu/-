#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& ):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		if (&d != this)//进行取引用对象d的地址，与this指针内进行比较，防止自身拷贝自身
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "Date operator=(const Date& ):" << this << endl;
		}
		return *this;//返回指针的解引用，用引用接收
	}

	Date& operator+(int day)
	{
		//if (day != 0)   重载时需要符合符号逻辑运算的规则，
		//{				  即：a+b=c中，a，b都未改变
		//	_day += day;
		//}
		//return *this;

		Date& temp = *this;
		temp._day += day;
		return temp;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(_year == d._year &&
			_month == d._month &&
			_day == d._day);
	}

	Date& operator++()
	{
		++_day;
		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date& operator--()
	{
		--_day;
		return *this;
	}

	Date operator--(int)
	{
		Date temp = *this;
		_day--;
		return temp;
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
	Date d1(2019, 4, 10);
	Date d2(d1);
	Date d3 = d2;

	d3 = d3 + 2;
	d2 = d2 + 5;

	if (d1 == d3)
		d2 = d2 + 1;

	if (d2 != d3)
		d3 = d3 + 2;

	int a = 1;
	a = a++;
	a = ++a;

	d1++;//为什么将d2换为d1就可以完成后置++
	++d1;
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}

	// d1 = d2 = d3;
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	void TestFunc1()//可读可写
	{
		this->_day++;
	}


	//在类内函数中，this指针被const修饰 --->  const Date* const this
	void TestFunc2() const //函数中对象的成员变量 不可被修改
	{
		//this->_day++;---> error  this指向的成员变量无法被修改
		//_year++;--->error
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
	Date d1(2019, 4, 10);
	const Date d2(2019, 4, 11); //d2常量不允许被修改==Date const d2()

	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}


	int _year;
	int _month;
	int _day;
};

Date& TestDate(Date& d)
{
	Date temp(d);
	temp._day += 1;

	return d;
}

void TestDate()
{
	Date d1(2019, 4, 10);
	Date d2(d1);
	d1 = TestDate(d2);
}

int main()
{
	TestDate();
	return 0;
}
#endif

