#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base" << endl;
	}
private:
	int _b;
};

class Derived : public Base
{
public:
	//调用默认的派生类构造函数时，(基类中构造函数参数必须存在，并且为不全缺省)
	//在初始化列表调用基类的构造函数
private:
	int _d;
};

int main()
{
	Derived d;//调用默认的派生类构造函数
	return 0;
}
#endif
#if 0
class Base
{
public:
private:
	int _b;
};

class Derived : public Base
{
public:
private:
	int _d;
};
int main()
{
	Derived d;
	//会析构派生类对象d，调用默认的派生类析构函数
}
#endif

#if 0
class Derived; //需要进行子类声明

class Base
{
public:
	friend void print(Base &b, Derived &d);

	//private 成员在什么情况下类外都都不可访问
protected:
	int _b = 10;
};

class Derived : public Base
{
public:
	friend void print1(Base &b, Derived &d);
protected:
	int _d = 20;
};	

void print(Base &b, Derived &d)
{
	cout << "Base:" << b._b << endl;
	cout << "Derived:" << d._d << endl;//error 因为友元并不会继承
}
void print1(Base &b, Derived &d)
{
	cout << "Base:" << b._b << endl; // error 因为友元并不会继承,所以，
									 // 子类中的友元也不能访问基类中的保护成员
	cout << "Derived:" << d._d << endl;
}

int main()
{
	Base b;
	Derived d;
	print(b, d);
	print1(b, d);
	return 0;
}
#endif

#if 0
#include<string>
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _stuNum; // 学号
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}
#endif

#if 0
class Base
{
public:
	void PrintBaes()
	{
		cout << static_b << endl;
		//cout << static_d << endl;//error.基类无法调用派生类中的静态成员函数
	}
protected:
	int _b = 10;
	static int static_b;
};
int Base::static_b = 11;//静态成员初始化

class Derived : public Base
{
public:
	void Print()
	{
		cout << static_b << endl;//派生类中访问基类的静态成员
		cout << _d << endl;
	}
protected:
	int _d = 20;
	static int static_d;
};
int Derived::static_d = 12;

int main()
{
	Derived d;
	d.Print();
	return 0;
}
#endif
