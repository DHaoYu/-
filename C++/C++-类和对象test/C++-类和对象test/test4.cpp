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
		if (&d != this)//����ȡ���ö���d�ĵ�ַ����thisָ���ڽ��бȽϣ���ֹ����������
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << "Date operator=(const Date& ):" << this << endl;
		}
		return *this;//����ָ��Ľ����ã������ý���
	}

	Date& operator+(int day)
	{
		//if (day != 0)   ����ʱ��Ҫ���Ϸ����߼�����Ĺ���
		//{				  ����a+b=c�У�a��b��δ�ı�
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

	d1++;//Ϊʲô��d2��Ϊd1�Ϳ�����ɺ���++
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

	void TestFunc1()//�ɶ���д
	{
		this->_day++;
	}


	//�����ں����У�thisָ�뱻const���� --->  const Date* const this
	void TestFunc2() const //�����ж���ĳ�Ա���� ���ɱ��޸�
	{
		//this->_day++;---> error  thisָ��ĳ�Ա�����޷����޸�
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
	const Date d2(2019, 4, 11); //d2�����������޸�==Date const d2()

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

