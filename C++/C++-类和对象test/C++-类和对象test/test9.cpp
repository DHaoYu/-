#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
class Date
{
public:
	friend ostream& operator<<(ostream& cout, const Date& d);
	Date(int year = 2019, int month = 10, int day = 23)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._year << d._month << d._day << endl;
	return cout;
}

int main()
{
	Date d;
	//d << cout;
	cout << d;//这样就正常多了
	return 0;
}
#endif

#if 0
class B
{
	friend class A;
public:
	B()
	{
		_b1 = 10;
		_b2 = 20;
	}
private:
	int _b1;
	int _b2;
};

class A
{
public:
	void print()
	{
		cout << "B::_b1 = " << _b._b1 << endl;
		cout << "B::_b2 = " << _b._b2 << endl;
		cout << "A::_a = " << _a << endl;
	}
private:
	int _a = 100;
	B _b;
};

int main()
{
	A a;
	a.print();
	return 0;
}
#endif

#if 0
class B
{
	friend class A;
public:
	B()
	{
		_b1 = 10;
		_b2 = 20;
	}
	void print()
	{
		cout << "A::_a = " << a._a << endl;
	}
private:
	int _b1;
	int _b2;
	A a;
};

class A
{
public:
private:
	int _a = 100;
};

int main()
{
	B b;
	b.print();
	return 0;
}
#endif

class A
{
public:
	class B
	{
	public:
		void print(const A& a)
		{
			cout << _sa << endl;//访问外部类中的static成员变量
			cout << a._a << endl;//通过a对象来调用A类私有成员变量
		}
	private:
		int _b;
		static int _sb;
	};
private:
	int _a = 0;
	static int _sa;
};

int A::B::_sb = 10;//static初始化方式
int A::_sa = 20;

int main()
{
	return 0;
}