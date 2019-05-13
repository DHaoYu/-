#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
//计算类中总共创建了多少个对象？-->需要定义全局变量
//不能将变量定义在每个对象中，应该是所有对象共享
//1.使用全局变量--->缺陷：不安全

class Test
{
public:
	Test()
		:_a(0)
		//, _count(0)--->不可以在此处进行初始化，需要放在类外进行初始化
	{
		_count++;
	}

	Test(Test& t)
	{
		_count++;
	}


	~Test()
	{
		_count--;
	}
private:
	int _a;
	static int _count;
};

int Test::_count = 0;//  -----  声明 需要加上数据类型

int main()
{
	Test t1, t2;
	Test t3(t1);
	
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test()
		:_a(1)
	{
		cout << "Test():" << this << endl;
	}

	//普通成员函数含有this指针，可以访问普通成员变量以及非静态成员变量
	int Getprivate()
	{
		return _a;
	}

	static int Getstatic()//静态成员函数：不含this指针，不能访问普通成员变量
	{
	//	Getprivate();//error 无法调用
		return _count;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

//	static int _count;放在public中进行有一定的错误

private:
	int _a;
	static int _count;
};

//int Test::_count = 0;//初始化在类得外部进行

int main()
{
	Test t;
	cout << t.Getprivate() << endl;
	cout <<Test::Getstatic() << endl;///访问静态成员变量必须加上作用空间
	return 0;
}
#endif


#if 0
class Time
{
	friend void Testfriend();
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << _hour << endl;
	}



private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
	friend ostream& operator<<(ostream& cout,const Date& d);

public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int ,int ,int ):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void operator<<(ostream& cout)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	friend void Testfriend();

private:
	int _year;
	int _month;
	int _day;
};

void Testfriend()
{
	Time t;
	t._hour = 16;

	Date d;
	d._year = 2019;
}

//条件
//1. 两个参数，参数一定为ostream的引用，和需要输出的内容
//2. 必须要有返回值，以确保可以进行连续输出
//3. 在输出运算符重载中少进行换行操作，可以尽量不出错
//4. 该函数必须得作为类的友元函数---在类中必须设置成为友元
ostream& operator<<(ostream& cout,const Date & d)
{
	cout << d._year << "-" << d._month << "-" << d._day;
	return cout;
}

int main()
{
	Date d(2018, 4, 14);
	d.PrintDate();

	d.operator<<(cout);//如果在输出运算符重载在类内进行，会导致
	//输入输出颠倒，所以，将其放在类外进行输出输入重载
	//d << cout;

	//需要将其定义为类中的友元函数
	cout << d << endl;
	return 0;
}
#endif

#if 0
class Time
{
	friend class Date;//相似的
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << this->_hour << endl;
	}

	void TestFriendClass()
	{
		Date d;
		d._year = 2019;
	}

private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
	friend class Time;//在每一个类中都可以作为另外一个类的友元类，
					  //保证多个类的良好的交流能力
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}
#endif