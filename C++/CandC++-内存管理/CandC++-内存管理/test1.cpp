#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
int main()
{
	int* p = (int*)malloc(sizeof(int)* 3);
	memset(p, 0, sizeof(int)* 3);

	return 0;
}
#endif

#if 0
int main()
{
	//单个元素的空间
	int* p1 = new int;
	int* p2 = new int(10);
	//对应需要用delete进行删除--->否则会导致内存泄漏
	delete p1;
	delete p2;

	//连续空间-->进行delete[]进行删除
	int* p3 = new int[10];
	int* p4 = new int[];

	delete[] p3;
	delete[] p4;

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}
	
	Test(const Test& t)
		:_t(t._t)
	{
		cout << "Test(const Test&):" << this << endl;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}

private:
	int _t;
};

void TestNewDelete()
{
	//new申请空间+调用构造函数
	Test* p1 = new Test;
	//delete释放空间+调用析构函数
	delete p1;

	//malloc申请空间但是---!未调用构造函数
	Test* p2 = (Test*)malloc(sizeof(Test));
	if (nullptr == p2)
		;
	free(p2);//释放空间但是--未调用析构函数

	Test* p3 = new Test[10];//申请十个连续的Test空间
	delete[] p3;//连续销毁是个Test空间，并且后构造的空间先申请
}

int main()
{
	TestNewDelete();
	return 0;
}
#endif

#if 0
#include<stdlib.h>
#include<crtdbg.h>

#define CRTDBG_MAP_ALLOC
//检测申请空间与释放空间的不匹配的情况下是否会出现问题

//对于内置类型，是否匹配使用没有影响
void TestFunc()
{
	int* p1 = (int*)malloc(sizeof(int));
	delete p1;

	int* p2 = (int*)malloc(sizeof(int));
	delete[] p2;

	int* p3 = new int;
	free (p3);

	int* p4 = new int[10];
	free(p4);

	int* p5 = new int;
	delete[] p5;

	int* p6 = new int[10];
	delete[] p6;
}

int main()
{
	TestFunc();
	_CrtDumpMemoryLeaks();//我的无法进行检测？？？--->黑人问好？？？
	return 0;
}
#endif

#if 0
#include<stdlib.h>
#include<crtdbg.h>

#define CRTDBG_MAP_ALLOC
//在类中进行内存检验，一定要将new[] 与 delete[] 匹配使用
class Test
{
public:
	Test()
	{
		_ptr = new int[10];
	}

	~Test()
	{
		delete[] _ptr;
		_ptr = nullptr;
	}
private:
	int* _ptr;

};

void TestFunc()
{
	
	//Test* p1 = (Test*)malloc(sizeof(Test));//没有调用构造函数
	//delete p1;//崩溃

	//Test* p2 = (Test*)malloc(sizeof(Test));//崩溃，没有调用构造函数
	//delete[] p2;

	//Test* p3 = new Test;
	//free(p3);//内存泄漏--->空间释放，但是对象中的资源没有被销毁

	//Test* p4 = new Test[10];
	//free(p4);//崩溃+内存泄漏

	//Test* p5 = new Test;//申请一个Test类空间，无法释放多个
	//delete[] p5;//崩溃

	//Test* p6 = new Test[10];
	//delete p6;//崩溃+内存泄漏
}

int main()
{
	TestFunc();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	//~Test()
	//{
	//	cout << "~Test():" << this << endl;
	//}

private:
	int _data;
};

int main()
{
	Test* p1 = new Test;
	delete p1;//如果析构函数未给出，delete会释放空间，但是不会调用析构函数

	Test* p2 = new Test[10];
	delete[] p2;

	return 0;
}
#endif

