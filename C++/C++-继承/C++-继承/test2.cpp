#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class A
{
public:
	void Test()
	{
		cout << _a << endl;
	}
protected:
	int _a = 10;
	int _b = 20;
	int _c = 30;
};

class B : public A
{
public:
	//在子类中如果有成员名称和父类中的相同，这种情况下，子类会屏蔽掉
	//父类中的相同名称成员，这种情况叫做（同名隐藏）重定义
	//AB中的两个Test函数并未构成重载，因为这两个函数不在同一个作用域中
	void Test()
	{
		cout << _a << endl;
	}
private:
	int _a = 100;
};

int main()
{
	A a;
	B b;
	a.Test();
	b.Test();//发生同名隐藏关系
	return 0;
}
#endif

#if 0
//派生类中的默认成员函数

class Base
{
public:
	Base(int a)//当基类中不存在默认的构造函数，则需要派生类进行显式调用
		//（全缺省参数的构造函数子类可以隐式调用（不给出构造函数））
	{
		_a = a;
	}
protected:
	int _a;
	int _b;
	int _c;
};

class Derive : public Base
{
public:
	Derive(int d)
		:Base(1)
		, _d(d)
	{}
	void Func()
	{
		cout << _a<< _d << endl;
	}

//protected:
	int _d;
};

int main()
{
	Derive d(100);
	Derive* pd;
	Base* pb = new Base(5);
	pd = (Derive*)pb;
	pd->Func();
	d.Func();
	return 0;
}
#endif

#if 0
//类对象模型
class Base
{
public:
	Base()
	{
		_a = 1;
		_b = 2;
		_c = 3;
	}
protected:
	int _a;
	int _b;
	int _c;
	//char _a;//16字节
	//int _b;
	//double _c;
	//char _b;//24字节
	//double _c;
	//int _a;
};

class Derive : public Base
{
public:
	Derive()
	{
		_d = 4;
	}

	void Func()
	{
		cout << _a << _d << endl;
	}
protected:
	int _d;
};

int main()
{
	Base b;
	Derive d;
	cout << sizeof(b)<< " "<< sizeof(d) << endl;
	return 0;
}
#endif 

#if 0
//继承中六个默认成员函数
class Base
{
public:
	Base()
	{
		_a = 1;
		_b = 2;
		_c = 3;
	}

	Base& operator=(Base& b)
	{
		_a = b._a;
		_b = b._b;
		_c = b._c;

		return  *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _a;
	int _b;
	int _c;
};

class Derive : public Base
{
public:
	Derive()
	{
		_d = 4;
	}

	Derive& operator=(Derive& d)
	{
		*this = d;
		_d = d._d;
		return *this;
	}

	~Derive()
	{
		cout << "~Derive()"<<endl;
	}

	void Func()
	{
		cout << _a << _d << endl;
	}
protected:
	int _d;
};

int main()
{
	Derive d;//可以用派生类对象拷贝构造基类对象
	Base b(d);
	//Derive d(b);//error 不可以用基类对象拷贝构造派生类对象,基类对象
						//无法强转为派生类对象，但是基类指针可以
	Derive d1 = d;
	Base b1 = d;
	return 0;
}
#endif
