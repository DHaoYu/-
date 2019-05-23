#include<iostream>
#include<stdio.h>
using namespace std;

#if 0
//const定义常量
int main()
{
	const int val1 = 10;//
	//val1 = 100;error const data
	int const  val2 = 20;
	//val2 = 10;error const data
	//extern const int val = 100;--->???

	return 0;
}
#endif

#if 0
int main()
{
	const int val = 10;//在预编译阶段将代码中所有变量val进行了修改-->直接改为常量
	cout << val << endl;
	int* pval = (int*)&val;
	*pval = 100;
	cout << val << endl;
	cout << *pval << endl;//pval 不是const变量	
	return 0;
}
#endif

#if 0
//指针使用const

int main() 
{
	int val1 = 10;
	int val2 = 20;
	int const* p1 = &val1;
	const int* p2 = &val1;
	int* const p3 = &val1;
	const int* const p4 = &val1;
	*p1 = 100;//error non-const pointer , const data
	p1 = &val2;
	*p2 = 100;//error non-const pointer , const data
	p2 = &val2;
	*p3 = 100;
	p3 = &val2;//error const pointer , non-const data
	
	*p4 = 100;
	p4 = &val2;//error const pointer , onst data

	return 0;
}
#endif

#if 0
//引用使用const
int main()
{
	const int a = 10;//const类型对象只能用const进行引用
	const int& ra = a;
	cout << ra << endl;
	int const& rb = a;
	cout << rb << endl;
	//error int& const rc = a; //warning 直接将const限定符进行了忽略
	const int* pa = &ra;
	return 0;
}
#endif


//在函数中使用const
#if 0 //参数传递
void Test1(const int val)//==int const val
{
	val = 100;
}

void Test2(int const* pa)//== const int* val
{
	int a = 1;
	pa = &a;
	*pa = 100;
}

void Test3(int* const pa)
{
	int a = 1;
	pa = &a;
	*pa = 100;
}
//Test1,2,3 和定义参数的const用法与c语言中相同
#endif

#if 0
//引用类型参数传递
void Test1(const int& a)
{
	int b = 20;
	a = 100;//const data
	a = b;// error 无法引用其他变量
}

void Test2(int const& a)
{
	a = 100;
}

int Test3(int& const a)//warning 直接忽略了限定符
{
	int b = 20;
	a = 100;
	return a;
}
#endif

#if 0
//返回值的const用法
//一般情况下，函数的返回值为某个对象时，如果将其声明为const时，多用于操作符的重载。
//通常，不建议用const修饰函数的返回值类型为某个对象或对某个对象引用的情况
const int Test1()
{
	int a = 10;
	return a;
}

const int * Test2()// == int const * Test2()
{
	int a = 10;
	int* pa = &a;
	return pa;
}

int* const Test3()
{
	int a = 10;
	int* pa = &a;
	return pa;
}
int const* const Test4()//都不可进行修改
{
	int a = 10;
	int* pa = &a;
	return pa;
}

int main()
{
	int a = 100;
	const int* const pa1 = Test2();
	const int* pa1 = Test2();//必须需要使用const类型的指针进行接受
	int* pa2 = Test3();//返回指针指向不可修改的指针，可以用普通指针变量进行接受
	pa2 = &a;		   //也可以改动指针的指向（拷贝了一份地址返回）
	
	return 0;
}
#endif

#if 0
class Test
{
public:
/*	Test()
	{
		_a = 10;//error 在构造函数内部进行初始化const成员
	}*/

	Test()
		:_a(10) //在类中修饰const成员时，只能在初始化列表对其进行初始化
	{}
/*	void Func()
	{
		_a = 100;//无法被修改
	}*/
private:
	const int _a;//成员常量不能被修改
};

int main()
{
	Test t;
	return 0;
}
#endif

#if 0
//const 修饰类中成员函数
//则该成员函数是不能修改类中任何非const成员的函数。一般写在函数的最后来修饰
class Test
{
public:
	Test()
		: _a(10)
	{}

/*	void Func1()const
	{
		_a = 100; // error 不能修改当前对象的任何成员变量
	}*/

	void Func2(int b = 10)const
	{
		b = 100; // 可以修改形参的值
	}

	void Func3()const
	{}
	void Func4()
	{}
	void Func5()const
	{
		Func3();
		//_a = 100;// error const类型的成员函数无法访问非const类型的成员变量
		//Func4();//error const 成员函数中不能调用非const修饰的成员函数
	}
private:
	int _a;
};

int main()
{	
	const Test t;
	//t.Func4();//error 对象无法调用非const类型的成员函数
	//const类型的对象、引用、指针都无法调用非const类型的成员函数
	return 0;
}
#endif

#if 0
//将const类型转换未非const类型
//黑人问号 ？？？
int main()
{
	const int a = 10;
	const int* pa = &a;
	int& c = const_cast<int&>(a);
	c = 100;
	cout << a << c << endl;
	return 0;
}
#endif

#if 0
const int& Test()
{
	int a = 10;
	return a;
}

int main()
{
	int b = Test();
	cout << b;
	b = 100;
	cout << b;
	return 0;
}
#endif
