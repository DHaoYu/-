#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

//单继承
//多继承
//class 默认的继承方式是private， struct 默认的继承方式为public
#if 0
class Base
{
public:
	int _b = 10;
};

class Derived : Base //class默认的继承方式为私有private继承
{
private:
	int _d;
public:
	void Test()
	{
		_b = 100;
		//cout << _b << endl;
	}
};

int main()
{
	Derived d;
	d._b = 100;
	d.Test();
}
#endif

#if 0
struct Base
{
public:
	int _b = 10;
};

struct Derived : Base //struct默认的继承方式为共有public继承
{
private:
	int _d;
public:
	void Test()
	{
		_b = 100;
		//cout << _b << endl;
	}
};

int main()
{
	Derived d;
	d._b = 100;
	cout << d._b << endl;
	d.Test();
}
#endif

//菱形继承

