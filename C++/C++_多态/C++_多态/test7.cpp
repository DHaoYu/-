#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 1
class A
{
public:
	virtual void Func()
	{
		cout << "A::Func()" << endl;
	}
protected:
	int _a = 1;
};

class B : virtual public A
{
public:
	virtual void Func()
	{
		cout << "B::Func()" << endl;
	}
protected:
	int _b = 2;
};

class C : virtual public A
{
public:
	virtual void Func()
	{
		cout << "C::Func()" << endl;
	}
protected:
	int _c = 3;
};

class D : public B, public C
{
public:
	virtual void Func()
	{
		cout << "D::Func()" << endl;
	}
protected:
	int _d = 4;
};
int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B1
{
	virtual void Func()
	{
		cout << "B1::Func()" << endl;
	}
	int b1 = 10;
};

class B2 : public B1
{
	virtual void Func()
	{
		cout << "B2::Func()" << endl;
	}
	int b2 = 11;
};

class D : public B2
{
	virtual void Func()
	{
		cout << "D::Func()" << endl;
	}
	int d1 = 20;
};

int main()
{
	D d;
	return 0;
}
#endif
