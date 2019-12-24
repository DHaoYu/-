#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
class A
{
public:
	virtual void Func() = 0;
};

class B : public A
{
public:
	virtual void Func() override //表示强制重写虚函数
	{
		cout << "virtual B::Func()" << endl;
	}
};

int main()
{
	A *b = new B();
	b->Func(); //编译器会首先检测其静态类型是否合法
}
#endif

#if 0
class A
{
public:
	virtual void Func() = 0;
};

class B : public A
{
public:
	virtual void Func() final //表示禁止再被重写
	{
		cout << "virtual B::Func()" << endl;
	}
};

class C : public B
{
public:
	virtual void Func() //error
	{
		cout << "virtual C::Func()" << endl;
	}
};
#endif

#if 0
//虚函数表
class B
{
public:
	virtual void Func()
	{
		cout << "Func()" << endl;
		cout << Func << endl;
	}

private:
	int _a = 1;
};

int main()
{
	B b;
	b.Func();
	cout << sizeof(B) << endl;
}
#endif

#if 0
class B
{
public:
	virtual void Func()
	{
		cout << "Func()" << endl;
	}

	virtual void fff()
	{

	}

private:
	int _a = 1;
};

class D : public B
{
public:
	virtual void Func()
	{
		cout << "D::Func()" << endl;
	}
	virtual void F()
	{
		cout << "F" << endl;
	}
private:
	int _d;
};

int main()
{
	B b;
	D d;
	cout << sizeof(D) << endl;
}
#endif

class B
{
public:
	virtual void Func()
	{
		cout << "B::Func()" << endl;
	}
};

class D : public B
{
public:
	virtual void Func()
	{
		cout << "D::Func()" << endl;
	}
};

void Fun(B& b)
{
	b.Func();
}

int main()
{
	B b;
	D d;
	Fun(b);
	Fun(d);

}



	//B *pd = new D();
	//B *pb = new B();
	//pd->Func();
	//pb->Func();
//}