#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#if 0
class Test
{
private:
	char _c1;
	int _a;
};

class T
{
private:
	Test t;
	char _c;
};

int main()
{
	cout << sizeof(T) << endl;//T进行了内存对齐

	return 0;
}
#endif

#if 0
class T1
{
public:
	T1(char c = 'c', int b = 1, double a = 1.0)
		:_c(c)
		, _b(b)
		, _a(a)
	{}
	char  _c;
	int _b;
	double _a;
};

class T2
{
public:
	T2(char c = 'c', int b = 1, double a = 1.0)
		:_c(c)
		, _b(b)
		, _a(a)
	{}
	char _c;
	double _a;
	int _b;
};

int main()
{
	T1 t1;
	T2 t2;
	cout << "T1 size is :" << sizeof(T1) << endl;//元素在类中的排列顺序不同，
	cout << "T2 size is :" << sizeof(T2) << endl;//最后类占用内存大小也可能不同

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
	}
	Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;//error 全缺省参数和无参的构造函数称为默认构造函数，只能存在一个
	return 0;
}
#endif

#if 0
class Test1
{
public:
	void TestFunc()
	{}

	int _data;
};

class Test2
{
public:
	void TestFunc()
	{}

	int _data;
};

int main()
{
	Test1 t1;
	t1.TestFunc();

	Test2 t2;
	t2.TestFunc();

	return 0;
}
#endif

#if 0
class Test
{
public:
	void TestFunc()
	{}
	
	int _data;
};

int main()
{
	Test t;
	t.TestFunc();
	cout << sizeof(Test) << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	explicit Date(int year)
	{
		_year = year;
	}

	
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1999);//如果没有explicit，编译器在将2020赋值时会将其隐式转化为Date
	d1 = 2000;//explicit加在构造函数前，禁止隐式的将2020(单个参数)转换为Date类型临时对象
	return 0;
}
#endif

#if 0
//C++11
class T
{
public:
private:
	//static int _count = 0;//error 
	int _a = 0;//在C++11中，非静态成员变量的初始化可以直接放在声明时进行初始化
	int b = 0;
	int* array = new int[10];
};

int main()
{
	T t;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{}

	static void TestFuncSta()
	{
		cout << _a << endl;
		//cout << _b << endl;同理无法调用普通成员变量
		//TestFunc1();//error 因为普通成员函数中都存在默认的this指针
		//静态成员函数中没有this指针，所以无法调用普通成员函数
	}

	void TestFunc1()
	{
		TestFuncSta();//普通成员函数可以访问静态成员函数，可以正常传参
		cout << _a << _b << endl;//成员变量也都可以访问
	}

	~Test()
	{}

private:
	static int _a;
	int _b;
};

int Test::_a = 0;

int main()
{
	Test t;
	t.TestFunc1();
	return 0;
}
#endif