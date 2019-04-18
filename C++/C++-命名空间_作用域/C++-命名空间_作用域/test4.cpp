#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>

using namespace std;

#if 0
int main()
{
	char c = 'c';
	char& rc = c;

	char* pc = &c;
	int ** p = NULL;
	const char&& rrc = 'c';//C++：右值引用：对右值进行绑定的引用叫做右值引用
	return 0;
}
//主函数无法重载
/*
int main(int a)
{
	return 0;
}
*/
#endif

//右值引用：增加变量的作用周期
#if 0
#include <iostream>
using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
	A(){
		cout << "construct: " << ++g_constructCount << endl;
	}

	A(const A& a)
	{
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}
	~A()
	{
		cout << "destruct: " << ++g_destructCount << endl;
	}
};

A GetA()
{
	return A();
}

int main() {
	A a = GetA();
	return 0;
}
#endif

#if 0
class A
{
public:
	A() 
		:m_ptr(new int(0))
	{ cout << "construct" << endl; }

	A(const A& a)
		:m_ptr(new int(*a.m_ptr)) //深拷贝的拷贝构造函数
	{
		cout << "copy construct" << endl;
	}
	~A(){ delete m_ptr; }
private:
	int* m_ptr;
};

A GetA()
{
	return A();
}


int main() {
	A a = GetA();
	return 0;
}
#endif 

#if 0
int main()
{
	char c = 'c';

	char& rc = c;

	char&& rrc = 'c';
	char& rb = 'c';//error
}
#endif

#if 0
#define MaxSize 100
//宏定义，宏常量
struct SeqList
{
	int array[MaxSize];
	int _size;
};

#define PI 3.14

int main()
{
	int r = 2;
	double s = PI * r * r;
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	(*pa) = 20;

	cout << a << endl;
	cout << *pa << endl;
	return 0;
}
#endif

#if 0
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
//宏函数，会引起一些其他类型的副作用
//宏函数会在编译过程中直接将其进行替换
//做预处理器符号表中的简单替换
int main()
{
	int a = 10;
	int b = 10;
	cout << MAX(a, b) << endl;
	cout << MAX(a, b++) << endl; //error：a++无法进行++ 
	// (a)>(b++) ? (a) : (b++)
	return 0;
}
#endif

#if 0
//内联函数inline
//简单的概括就是宏定义表达式或函数
//无法发挥宏定义最大化，为了避免这些缺点，
//引入了 inline，这个inline既吸收了宏定义的优点，
//又扩展了，inline推出的目的就是消除宏定义的缺点，
//同时又很好地继承了宏定义的优点。

inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << Add(a, b) << endl;
	return 0;
}
#endif

