#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
//实现一个person类，实现买票功能
class Person
{
public:
	void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};
class Student : public Person
{
public:
	void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};

void TestFunc(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person P;
	Student S;
	P.BuyTicket();
	S.BuyTicket();
	TestFunc(P);
	TestFunc(S);//进行传参，TestFunc函数中参数的类型是基类类型，所以在传参数后
				//会进行静态绑定调用类内成员函数，所以Student调用Person类成员函数
	return 0;
}
#endif

#if 0
//为了实现多态情况，所以需要基类与派生类中将函数改为虚函数
class Person
{
public:
	virtual void BuyTicket()//虚函数使用的绑定类型是动态绑定
	{
		cout << "买票-全价" << endl;
	}
};
class Student : public Person
{
public:
	//虚函数重写：派生类中有一个跟基类中完全相同的虚函数，我们就称派生类中的
	//虚函数重写了基类中的虚函数。完全相同指（函数名，参数，返回值都相同）
	void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
};

void TestFunc(Person& p)
{
	p.BuyTicket();//在调用时，先进行判断动态绑定类型是什么，然后在进行类内成员函数的调用
}

int main()
{
	Person P;
	Student S;
	TestFunc(P);
	TestFunc(S);

	return 0;
}
#endif

#if 0
//虚函数重写的协变
//协变：在重写的虚函数中，返回值可以不同，但是必须分别是基类的指针和派生类的指针，
//或者引用
//可以是自身类的基类和派生类也可以是其他类的基类和派生类
class A
{};

class B : public A
{};

class Person
{
public:
	virtual A* Func()
	{
		cout << "return new A" << endl;
		return new A;
	}

	virtual B* Func2()
	{
		cout << "return new A" << endl;
		return new B;
	}

	virtual Person& Func1()
	{
		cout << "return Person&" << endl;
			return *this;
	}
};

class Student : public Person
{
public:
	virtual B* Func()
	{
		cout << "return new B" << endl;
		return new B;
	}

	/*virtual A* Func2()//error 既不是协变又不是虚函数重写，所以报错
	{
		cout << "return new A" << endl;
		return new A;
	}*/

	virtual Student& Func1()
	{
		cout << "return Student&" << endl;
		return *this;
	}
};

void TestFunc(Person& p)
{
	p.Func();
	p.Func1();
}

int main()
{
	Person p;
	Student s;
	TestFunc(p);
	TestFunc(s);
	return 0;
}
#endif

#if 0
//重写格式，一般将其规范化
//在派生类中，重写的虚函数前可以不加virtual修饰，也可以构成重写，因为继承后基类的虚函数
//被继承下来了在派生类中依旧保持原有的属性，只是进行了重写，但这是不规范的

class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价" << endl;
	}
};

class Student : public Person
{
public:
	void BuyTicket()//不规范写法，在其前面加上virtual使其规范化
	{
		cout << "半价" << endl;
	}
};
#endif

#if 0
class Person
{
public:
	~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	~Student()
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	Person P;
	Student S;
	//P.~Person();
	//S.~Student();
	return 0;//析构函数在最后自行调用
}
#endif

#if 0
//析构函数的重写：基类中的析构函数如果是虚函数，则派生类的析构函数就重写了基类的
//析构函数，虽然他们的函数名不同，但是，可以来理解为编译器将析构函数做了特殊的处理，
//编译后，将其通一进行了命名。   *基类中的析构函数最好写成虚函数*
class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	~Student()
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;//如果基类不定义virtual函数的话，将存在静态绑定，可能存在问题

	delete p1;
	delete p2;
	return 0;
}
#endif




