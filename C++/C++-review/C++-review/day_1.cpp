#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<stdio.h>

using namespace std;

#if 0
bool Func()
{
	bool a = 1, b = 0;
	return a&b;
}

//inline void Func()
//{
//	cout << 1 + 2 << endl;
//}
#if 0
class Class
{
public:
	void func()
	{
		cout << "..." << endl;
	}

private:
	int _a;
	char _b;
	static int c;
};

class Date
{
	void operator+(Date& d)
	{
		_year += d._year;
		_month += d._month;
		_day += d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

namespace N1
{
	int _a = 100;
	void Func()
	{
		cout << "..." << endl;
	}
}

namespace N2
{
	int _a = 10;
	void Func()
	{
		cout << "123" << endl;
	}
}
#endif

int main()
{
	//N1::_a;
	//N2::Func();
	cerr << "asadf" << endl;

	//int a = 10;
	//auto b = a;
	//throw b;
	//try
	//{
	//	func1();
	//}
	//catch (...)
	//{
	//	func2();
	//}
	return 0;
}
#endif
//
//int add(int left , int right)
//{
//	return left + right;
//}
//
//double add(double left, double right)
//{
//	return left + right;
//}
//
//int add(int left, int mid, int right)
//{
//	left += mid;
//	return left + right;
//}

#if 0
int add(int left, int right); 
double add(double left, double right);

int main()
{
	add(1, 2);
	add(1.1, 2.2);
	return 0;
}
#endif