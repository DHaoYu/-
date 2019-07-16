#define _CRT_SECURE_NO_WARNNINGS 1
#include<string>
#include<iostream>
using namespace std;

#if 0
template<class T>
class Printer
{
public:
	Printer(T& t)
		:_t(t)
	{}

	string&& to_string();//定义在外部

	void print()//定义在内部
	{
		cout << _t << endl;
	}
private:
	T _t;
};

template<class T>
string&& Printer<T>::to_string()
{
	strstream ss;
	ss << t;
	return std::move(string(ss.str()));
}

int main()
{
	//Printer p(1);error 没有实例化类型
	int a = 10;
	Printer<int> p1(1);//所传参数为常量，想要引用常量，必须将变量名加上const修饰。
	Printer<int> p(a);
	return 0;
}
#endif

#if 0
class Printer
{
public:
	Printer(int& t)//引用情况下，不能引用常量，因为常量在内存中存储位置在常量区
		:_t(t)
	{}

private:
	int _t;
};

int main()
{
	Printer p1(12);//
	return 0;
}
#endif

#if 0
template<class T>
class Printer
{
public:
	Printer(const T& t)
		:_t(t)
	{}


	template<class U>
	void print(const U& u)//定义在内部
	{
		cout << u << endl;//成员函数模板可以自行推演进行隐式实例化
		cout << _t << endl;
	}
private:
	T _t;
};


int main()
{
	Printer<int> p(1);
	p.print('a');
	return 0;
}
#endif

#if 0

template<class T>
class Printer
{
public:
	Printer(const T& t)
		:_t(t)
	{}

	void print()//定义在内部
	{
		cout << _t << endl;
	}
public:
	static int _val;
private:
	T _t;
};

template<class T>
int Printer<T>::_val = 1;//静态成员需要在类外进行初始化，初始化时需要加上模板参数T
//所有的类内声明在类外定义时都需要加上

int main()
{
	Printer<int> pi1(1);
	Printer<int> pi2(2);
	Printer<double> pd1(1.1);
	cout << &pi1._val << endl;//pi1与pi2实例化的类型相同，初始化时生成一份static成员共用
	cout << &pi2._val << endl;
	cout << &pd1._val << endl;//pd1定义的是double类型，所以在所有的double类型对象中，共用一份
	return 0;
}
#endif

#if 0
//默认实参
template<class T,class F = less<T>>
int compare(const T& left, const T& right, F f = F())//创建无名对象，赋值给f
{
	if (f(left, right))//调用f构造函数
	{
		cout << "left" << endl;
	}
	if (f(right, left))
	{
		cout << "right" << endl;
	}
	return 0;
}

int main()
{
	compare(1, 2);
	compare(3, 2);
	return 0;
}
#endif

