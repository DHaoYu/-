//继承 可以使代码复用，体现了程序设计语言的的层次结构，之前都是
//函数服用，C++类中可以实现类的复用。
#include<iostream>
#include<string>
using namespace std;

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "Peter";
	int _age = 18;
};

class Teacher : public Person
{
protected:
	int _jobid=0;
};

class Student :public Person
{
protected:
	int _stuid=0;
};

int main()
{
	Student s;
	Teacher t;
	Person p;
	s.Print();
	t.Print();
	p.Print();
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	int _a;
protected:
	string _name = "Peter";
	int _age = 18;
private:
	int _b = 0;
};

class Teacher : public Person
{
public:
	void Print()
	{
		cout << _name << _age + 1<< endl;
		//cout << _b << endl;//子类中不能访问基类的private成员
	}
protected:
	int _jobid = 0;
};

int main()
{
	Teacher t;
	t.Print();//
	//t._name;protected private成员不可在类外访问。
	//protected 成员在子类中可以被访问，但是，private成员在子类中无法被访问
	return 0;
}
#endif

#if 0
//派生类对象可以赋值给基类对象/基类指针/基类的引用

class Person
{
public:
	string _name;
	string _sex;
	int _age;
};

class Student :public Person
{
public:
	int _No;//ID
};

int main()
{
	Person p;
	Student s;
	Person p1 = s;//赋值
	Person* pp = &s;//指针
	pp->_name;//可以访问派生类中基类的成员变量，
	//pp->_No;error 但是无法访问派生类中的成员变量
	Person& p2 = s;//引用
	//Student s1 = p;error 会导致访问越界，
	//如果 基类中有a，b两个成员变量，派生类中又多出来一个c，就会导致生成的
	//派生类指针中存在c的地址空间，为了避免访问越界，所以，C++直接禁止这样的隐式转化
	return 0;
}
#endif 

#if 0
//动静态绑定
class E
{
public:
	virtual void func(int i = 0)
	{
		std::cout << "E::func()\t" << i << "\n";
	}
};
class F : public E
{
public:
	virtual void func(int i = 1)
	{
		std::cout << "F::func()\t" << i << "\n";
	}
};

void test2()
{
	F* pf = new F();
	E* pe = pf;
	pf->func(); //F::func() 1  正常，就该如此；
	pe->func(); //F::func() 0  哇哦，这是什么情况，调用了子类的函数，却使用了基类中参数的默认值！
	//因为参数变动之后，因为缺省参数值都是静态绑定（为了执行效率），所以在调用虚函数时，有可能出现预想之外情况
	//详情《Effective C++ 第三版》 条款37
}

int main()
{
	test2();
	return 0;
}
#endif
//动、静态类型在类的继承中的调用方法

class A
{
public:
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
};

class B : public A
{
public:
	/*void func()
	{
		cout << "B::func()" << endl;
	}*/
};

class C : public A
{
public:
	void func()
	{
		cout << "A::func()" << endl;
	}
};

#if 0
int main()
{
	A* pa;
	B* pb = new B();
	C* pnull = nullptr;//pnull静态类型直接在编译阶段指向了C;
	//pnull =(C*)pb;//指向B::func() 
	pa = pb;
	//pnull->func();
	pa->func();//再virtual函数调用时，先在动态绑定的类中进行调用，如果没有
	//该函数，则从基类中查找函数并进行调用
	pnull->func();//空指针异常，因为类中声明的函数为虚函数，虚函数进行的是
	//动态绑定，所以func在调用时，只会在运行时候才确定，这时发现pnull为空，所以异常
	return 0;
}
#endif 
