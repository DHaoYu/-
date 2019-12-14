#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
class A
{
protected:
	int _a = 1;
	int _b = 2;
};

class B : public A
{
public:
	void Print()
	{
		cout << _a << endl;//����A�е�_a��Ա
		cout << _b << endl;// ������
	}
protected:
	int _b = 12;
};

class C : public B
{
public:

protected:
	int _c;
};
int main()
{
	B b;
	b.Print();
	return 0;
}
#endif

class A
{
protected:
	int _a = 1;
	int _c = 11;
};

class B
{
protected:
	int _b = 2;
	int _c = 12;
};

class C : public A, public B
{
public:
	void Print()
	{
		cout << _a << endl;//����A�еĳ�Ա
		cout << _b << endl;//����B�еĳ�Ա
		cout << _c << endl;//�����Ա
	}
protected:
	int _c = 3;
};

int main()
{
	C c;
	c.Print();
}