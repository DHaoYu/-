#define _CRT_SECURE_NO_WARNNINGS 1
//���μ̳�
//����� 
#include<iostream>
using namespace std;
#if 0
class A //����
{ 
protected:
	int _a = 1;
};

class B : public A //B�̳�A
{
protected:
	int _b = 2;
};

class C : public A //C�̳�A
{
protected:
	int _c = 3;
};

class D : public B, public C //D�̳�B��C
{
public:
	void Print()
	{
		//cout << _a << endl;
		cout << &(B::_a) << endl;
		cout << &(C::_a) << endl;
	}
protected:
	int _d = 4;
};

int main()
{
	D d;
	d.Print();
}
#endif

class A //����
{
protected:
	int _a = 1;
};

class B : virtual public A //B�̳�A
{
protected:
	int _b = 2;
};

class C : virtual public  A //C�̳�A
{
protected:
	int _c = 3;
};

class D : public B, public C //D�̳�B��C
{
public:
	void Print()
	{
	}
protected:
	int _d = 4;
};

int main()
{
	D d;
	d.Print();
}