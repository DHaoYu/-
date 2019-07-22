#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>


using namespace std;

#if 0
//虚基表
//在继承体系中，多重继承以及菱形继承等有可能会存在二义性问题，所以，引入
//虚继承，使得继承体系中得二义性问题得到解决，
//虚基表指针，虚基表，虚表（虚函数表） 
class B
{
public:
	virtual void func1()
	{
		cout << "B::func1()" << endl;
	}

private:
	int _b=1;
};

class C1 : virtual public B
{
private:
	int _c1 = 2;
};

class C2 : virtual public B
{
private:
	int _c2 = 3;
};

class D : public C1 , public C2
{
public:
	virtual void func1()
	{
		cout << "D::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "D::func2()" << endl;
	}

private:
	int _d = 4;
};

int main()
{
	D d;
	cout << sizeof(d) << endl;
	return 0;
}
#endif

#if 0
//虚表指针（虚函数表指针）放在内存布局的第一个位置_vfptr，存放虚函数地址
class B
{
public:
	virtual void func1()
	{
		cout << "B::func1()" << endl;
	}

private:
	int _b = 1;
};

class C1 : virtual public B
{
private:
	int _c1 = 2;
};

class C2 :virtual  public B
{
private:
	int _c2 = 3;
};

class D : public C1, public C2
{
public:
	virtual void func1()
	{
		cout << "D::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "D::func2()" << endl;
	}

private:
	int _d = 4;
};

int main()
{
	D d;
	cout << sizeof(d) << endl;
	return 0;
}
#endif

