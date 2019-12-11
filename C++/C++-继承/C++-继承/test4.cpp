#define _CRT_SECURE_NO_WARNNINGS 1

//赋值兼容规则
//同名隐藏  在基类和子类中具有相同名称的成员（变量，函数）
//（重定义）如果用子类的对象来访问相同名称的成员，永远访问的是子类中的成员
//			相同名称的成员发生了同名隐藏

/*默认成员函数
1. 如果基类中不存在默认的构造函数，则派生类需要显式给出构造函数
2. 如果基类中是默认的构造函数（无参），则派生类可以不给出构造函数（使用默认的）
3. 派生类中的构造函数在其初始化列表中调用
*/


#if 0
class Base
{
public:
	Base(int b)
	{}
private:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
		:Base(2)
	{}
private:
	int _d;
};

int main()
{
	Derived d1;
	Derived d2;
	d1 = d2;
}
#endif

#include<iostream>
using namespace std;

#if 0
class Father
{
public: // 访问权限
	void FatherFunc()
	{
		cout << "i am father" << endl;
	}
protected: //访问权限
	int _a;
};

class Child : public Father
{
public: //访问权限
	void ChildFunc()
	{
		cout << "i am child" << endl;
	}
protected: //访问权限
	int _b;
};

int main()
{

}
#endif

#if 0
struct Base
{
	int _a = 10;
};

struct Derived : public Base
{
	int _b = 20;
};

int main()
{
	Derived d;
	cout << d._a << d._b << endl;
	return 0;
}
#endif

#if 0
class Base
{
public:
	int _a = 10;
	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

class Derived : public Base
{
public: //为了方便在类外直接调用，定义为public
	int _b = 20;
	//int _a = 100; //与基类中的_a同名，但值不同
	~Derived()
	{
		Base::~Base();
		_a = 200;
		cout << "~Derived"<< this << endl;
		cout << "a = " << _a << endl;
	}
};

int main()
{
	Base b;
	Derived d;
	cout << "Base: _a = " << b._a << endl;
	cout << "Derived: _a = " << d._a << endl;
}
#endif

#if 0
//友元关系不能被继承，因为友元关系不属于类的成员，继承只是继承基类的成员
//静态成员变量可以被继承下去，并且依旧满足静态特性
class Base
{
private:
	int _b = 10;
	//friend void TestFunc();
public:
	static int _count;
	Base()
	{
		cout << "Base" << this << endl;
	}

	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

int Base::_count = 0;

class Derived : public Base
{
private:
	int _d;
public:
	Derived() :Base()
	{
		_count++; // 静态成员可以继承下去
		cout << "Derived" << this << endl;
	}
};
/*
void TestFunc()
{
	Base b;
	b._b = 200;//可以进行修改
	cout << b._b << endl;
	Derived d;
	//d._d = 100;//友元关系没有被继承， 无法在testfunc中进行修改
	//cout << d._d << endl;
}
*/
int main()
{
	//TestFunc();
}
#endif

#if 0
//设计一个不能被继承的类
//C++98将构造函数设计为私有的,设计一个get(创建对象)的接口，这个接口需要是静态的
//如果是普通成员函数（必须需要通过对象调用），则无法在类外普通调用，所以，需要static

class Base
{
private:
	int _b;
	Base()
	{
		cout << "Base" << this << endl;
	}

	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

//C++11 final关键字
class Base final //final关键字标志继承
{

};
#endif

