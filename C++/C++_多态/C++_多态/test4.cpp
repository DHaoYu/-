#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTicket() //������Ʊ��������Ϊ�麯��
	{
		cout << "ȫ��Ʊ" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket() //������Ҫ�������е��麯��������д
	{
		cout << "���Ʊ" << endl;
	}
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "������Ʊ" << endl;
	}
};

void Func(Person& people)//���������ָ���������
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
	virtual A* Func() //����A*����ָ��
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
	virtual B* Func() //����B* ������ָ��
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