#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
//final修饰的基类虚函数不能被派生类重写
class Car
{
public:
	virtual void Drive()final
	{
		cout << "Car" << endl;
	}

	virtual void Buy() 
	{
		cout << "Car" << endl;
	}
};

class Benz : public Car
{
public:
	/*
	virtual void Drive()//error 在基类中已经禁止派生类重写虚函数
	{
		cout << "Benz" << endl;
	}
	*/
	virtual void Buy() override
	{
		cout << "Car" << endl;
	}
};


int main()
{

	return 0;
}
#endif

#if 0
class Base//基类中的虚表指针存放方式与内容
{
public:
	virtual void Func1()//存在虚函数，说明还存在一个_vfptr指针放在对象内部，
		//_vfptr可能放在前面，也可能放在类对象模型后面，具体根据平台决定（v-virtual/f-function）
	{
		cout << "Func1()" << endl;
	}
	//虚表指针存放虚函数的地址，虚函数表也简称虚表
private:
	int _b = 1;//int 占用4个字节
	char _c = 'a';//要进行内存对齐
};

int main()
{
	Base b;
	cout << sizeof(Base) << endl;
	return 0;
}
#endif

#if 0
//派生类中虚表指针存放方式与内容
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}

	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}

	void func3()
	{
		cout << "Base::func3()" << endl;
	}

private:
	int _b = 1;
	char _c;
};

//虚表存在于代码段，_vfptr为虚表指针存在于对象中，虚函数呵普通函数类似存在于代码段
//虚函数表本身是存放虚函数访问地址的指针数组，数组最后面有nullptr
class Derive : public Base
{
public:
	virtual void func()//func被重写了，所以在Derive中将虚表存放重写的函数func地址
	{
		cout << "Derive::func()" << endl;
	}
	//func2再派生类中没有被重写，所以在内部还是存放的基类中的func2的函数地址
	
	//派生类中自己定义的虚函数的函数地址放置在虚表的最后
	virtual void Func()
	{
		cout << "DeriveofBaseFunc" << endl;
	}

	//Base中的func3也被继承下来了，但是没有virtual修饰，所以是普通函数，不构成重写
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	cout << sizeof(b) << sizeof(d) << endl;
	return 0;
}
#endif


#if 0
//多态实现原理是按照动态绑定类型，调用基类指针或者引用，从而实现的
//运行期间，虚表的调用方式
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}

	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}

	void func3()
	{
		cout << "Base::func3()" << endl;
	}

private:
	int _b = 1;
	char _c;
};


class Derive : public Base
{
public:
	virtual void func()
	{
		cout << "Derive::func()" << endl;
	}

	virtual void Func()
	{
		cout << "DeriveofBaseFunc" << endl;
	}

private:
	int _d = 2;
};

void Func1(Base& b)
{
	b.func();
	b.func2();
	b.func3();
}

void Func2(Derive& d)
{
	d.Func();
	d.func();
	d.func2();
	d.func3();
}

int main()
{
	Base b;
	Derive d;
	Func1(b);
	Func1(d);//Derive 中没有重写func2--调用基类、重写了func--调用自己的、func3为继承的函数
	Func2(d);
	//Func2(b);//传基类对报错--无法进行引用
	return 0;
}
#endif