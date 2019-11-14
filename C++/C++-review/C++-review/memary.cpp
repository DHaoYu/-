#define _CRT_SECURE_NO_WARNINGS 
#if 0
#include<iostream>

using namespace std;

int globalVar = 1;
static int staticGlobalVar = 2;

void Func()
{
	static int staticVar = 3;
	int localVar = 4;

	int arr[10] = { 1, 2, 3, 4 };
	char ch[] = "abcd";
	char* pch = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}
int main()
{
	return 0;
}
#endif

#if 0
int main()
{
	int* ptr1 = new int;//动态申请一个int大小的空间
	int* ptr2 = new int(5); 
	//将ptr2指针所指向的空间中的值初始化为5
	int* ptr3 = new int[4];//动态申请连续的4个int大小的空间

	ptr3[1] = 1;//可以正常使用进行解引用等
	ptr3[2] = 2;
	//当然也要进行释放
	delete ptr1;
	delete ptr2;
	delete[] ptr3; //连续的空间需要加上[]进行释放
	return 0;
}
#endif

#if 0
#include<stdio.h>

int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", arr+i);
	}
	int max = arr[1];
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("%d", max);
}
#endif

#if 0
int main()
{
	int* ptr1 = new int;//动态申请一个int大小的空间
	int* ptr2 = new int(5);
	//将ptr2指针所指向的空间中的值初始化为5
	int* ptr3 = new int[4];//动态申请连续的4个int大小的空间

	ptr3[1] = 1;//可以正常使用进行解引用等
	ptr3[2] = 2;
	//当然也要进行释放
	delete ptr1;
	delete ptr2;
	delete[] ptr3; //连续的空间需要加上[]进行释放
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Test
{
public:
	Test()
		:data(10)
	{
		cout << "Test()" << this << endl;
	}
	Test(int _data)
		:data(10)
	{
		cout << "Test()" << this << endl;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int data;
};

void func1()
{
	Test* iptr1 = new Test; //调用默认的构造函数，如果用户显式给出，
	//则没有默认构造，则会出错
	Test* iptr2 = new Test(10); //调用带有参数的构造函数
	delete iptr1;
	delete iptr2;
}

int main()
{
	//func1();
	int* pint = new int;
	delete pint;
	Test* ptr = new Test[10];
	delete[] ptr;
	return 0;
}
#endif


