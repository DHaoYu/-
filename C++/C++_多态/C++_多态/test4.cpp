#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTicket() //基类买票函数必须为虚函数
	{
		cout << "全价票" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket() //子类需要将基类中的虚函数进行重写
	{
		cout << "半价票" << endl;
	}
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "优先买票" << endl;
	}
};

void Func(Person& people)//创建基类的指针或者引用
{
	people.BuyTicket();
}

int main()
{
	Person p;
	Student s;
	Soldier sd;
	Func(p);
	Func(s);
	Func(sd);
	return 0;
}
#endif

#if 0
class A
{
public:
	virtual A()
	{
		cout << "A()" << endl;
	}
};

class B :public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
};
#endif

#if 0
class A
{
public:
	virtual A* Func() //返回A*基类指针
	{
		cout << "A* Func()" << endl;
		return new A();
	}
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
};

class B :public A
{
public:
	virtual B* Func() //返回B* 派生类指针
	{
		cout << "B* Func()" << endl;
		return new B();
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};

void Fun(A* a)
{
	a->Func();
}

int main()
{
	A a;
	B b;
	Fun(&a);
	Fun(&b);
}
#endif

#if 0
class A
{
public:
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
};

class B :public A
{
public:
	virtual ~B()
	{
		cout << "~B()" << endl;
	}
};

int main()
{
	A* a = new A();
	B* b = new B();
	delete a;
	delete b;
}
#endif