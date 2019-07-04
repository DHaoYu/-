#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

#if 0
//单、多继承
class B1
{
protected:
	int _b1 = 1;
};

class B2
{
protected:
	int _b2 = 2;
};
//class D :public B1,B2 ---这样写的话，B2就为private继承
class D :public B2, public B1//对象模型按照继承的先后顺序在内存中进行排列
{
protected:
	int _d = 3;
};

int main()
{
	D d;
	return 0;
}
#endif

#if 0
//友元函数
class B
{
	friend void Display(B& b,D& d);
public:
	int _a = 1;
	int _b = 2;
};

class D : public B
{
public:
	int _d = 3;
};

void Display(B& b, D& d)
{
	cout << b._a << endl;
	cout << b._b << endl;
	cout << d._a << endl;
	cout << d._d << endl;


}

int main()
{
	B b;
	D d;
	Display(b, d);
	return 0;
}
#endif

#if 0
#include<string>
//友元函数这块不太明白
class Person 
{
public:  
	friend void Display(const Person& p, const Student& s); 
protected:    
	string _name; // 姓名
}; 

class Student : public Person 
{ 
protected:   
	int _stuNum; // 学号
};

void Display(const Person& p, const Student& s) 
{ 
	cout << p._name << endl;   
	cout << s._stuNum << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s);

	return 0;
}
#endif

#if 0
class point
{
	int x, y;
public:
	point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	point(point& p)
	{
		x = 10 + p.x;
		y = 10 + p.y;
		cout << "调用复制构造函数" << endl;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		cout << " ";
		return y;
	}
	~point()
	{
		cout << "析构" << endl;
	}
};


void f(point p)
{
	cout << p.getx();
	cout << p.gety() << endl;
}

int main()
{
	point p1(1, 2);
	point p2(p1);
	cout << p2.getx()<<p2.gety() << endl;
	f(p2);
	return 0;
}
#endif


#if 0
class Base
{
public:
	static int _count;//静态成员必须在类外进行初始化
	void func()
	{
		_count++;
	}
private:
	int _a;
	int _b; 
};

int Base::_count = 0;//初始化时不需要再加上static修饰，直接 数据类型 类名::_count = 0; 

class Derive : public Base
{
public:
	static int _countD;
	void func()
	{
		_countD++;
	}

private:
	int _d;
};

int Derive::_countD = 0;

int main()
{
	Base b;
	b.func();
	Derive d;
	d.func();
	cout << d._countD << endl;
	cout << d._count << endl;//派生类中的对象可以访问基类中的静态成员
	//cout << b._countD << endl;//error  基类中对象无法访问派生类中的静态成员
	return 0;
}
#endif