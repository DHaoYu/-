#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stdio.h>
using namespace std;


#if 0
//全缺省参数的函数
//半缺省参数的函数
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << a << b << c << endl;
}

void TestFunc2(int a, int b, int c = 30)
{
	cout << a << b << c << endl;
}
//半缺省函数只能将缺省值从右向左给出
//void TestFunc3(int a = 10, int b, int c)
//{
//
//}

int main()
{
	TestFunc1();
	TestFunc1(1, 2, 3);
	TestFunc1(1);
	TestFunc1(1, 2);
	TestFunc1(2, 3);

	TestFunc2(10, 20);
	TestFunc2(1, 2, 3);
	return 0;
}
#endif

#if 0
int g_a = 10;//全局变量

void TestFunc(int a = g_a)
{
	cout << a << endl;
}

int main()
{
	TestFunc();
	TestFunc(100);
	return 0;
}
#endif

#if 0
void TestFunc()
{}

int main()
{
	TestFunc(10);//调用参数过多--- = =#黑人问号？？
	TestFunc(10, 20);
	return 0;
}
#endif

#if 0

//函数重载：必须在相同的作用域，必须有相同的函数名
//只有返回值类型不同是构不成函数重载，参数列表必须不同（参数个数，参数类型，参数类型的次序）

//如果将1.0，2.0传入int函数，函数并没有生成相应类型的重载函数
//只是将double进行了强制类型转化，转为int型
int Add(int left, int right)
{
	cout << left + right << endl;
	return left + right;
}

//无法重载仅返回类型形同的函数
/*
double Add(int left, int right)
{
	return left + right;
}
*/

double Add(double left, double right)
{
	return left + right;
}


int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	//Add(1, 2.0);//没有找到参数类型合适的函数，所以无法进行匹配
	return 0;
}
#endif

#if 0
void TestFunc()
{}

void TestFunc(int a)
{}

void TestFunc(int a, int b)
{}

void TestFunc(double a)
{}

//void TestFunc(int b, int a)//函数重载与函数所设置的变量名称无关
//{}

void TestFunc(int a, double b)
{}

void TestFunc(double a, int b)
{}

int main()
{
	return 0;
}
#endif


#if 0
void TestFunc()
{}

void TestFunc(int a = 0)
{}

int main()
{
	TestFunc(10);
	//TestFunc();//如果所传实参为空，则编译器会进行报错来提醒
	return 0;
}
#endif


#if 0
//C语言编译器对函数名字修饰的规则
//调不出来，黑人问号？？？
int Add(int left, int right);// _Add:在编译器中


double Add(int left, int right);//_Add

int main()
{
	return 0;
}
#endif

#if 0
int Add(int left, int right);// 


double Add(int left, int right);

int main()
{
	return 0;
}
#endif

#if 0
//C++中，编译器对函数的名字的修饰规则
int Add(int left, int right); //(?Add@@YAHHH@Z)
double Add(double left, double right); //(? Add@@YANNN@Z)

double Add(double left, int right);//(?Add@@YANNH@Z)

int main()
{
	Add(10, 20);
	Add(1.0, 2.0);
	Add(1.0, 2);
	return 0;
}
#endif

#if 0
extern "C" double Add(double left, double right);//extern "C" 运用C语言环境进行编译运行
//{
//	return left + right;
//}

int main()
{
	Add(1.0, 2.0);
	return 0;
}
#endif


