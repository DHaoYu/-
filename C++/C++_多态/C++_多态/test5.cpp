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
	virtual void Func() override //��ʾǿ����д�麯��
	{
		cout << "virtual B::Func()" << endl;
	}
};

int main()
{
	A *b = new B();
	b->Func(); //�����������ȼ���侲̬�����Ƿ�Ϸ�
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
	virtual void Func() final //��ʾ��ֹ�ٱ���д
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
//�麯����
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