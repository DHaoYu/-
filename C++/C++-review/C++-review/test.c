//#define _CRT_SECURE_NO_WARNNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	const int a = 10;
//	int* pa = (int*)&a;
//	*pa = 100;
//	printf("%d", a);  //a = 100;
//	return 0;
//}


//#include<malloc.h>
//#include<stdio.h>
//
//int* Test()
//{
//	int* arr = (int*)malloc(10);
//	for (int i = 0; i < 10; i++)
//	{
//		*(arr++) = i;
//	}
//	return arr;
//}
//
//
//int main()
//{
//	int* arr = Test();
//	for (int i = 0; i < 10; i++)
//		printf("%d ", *(arr + i));
//	return 0;
//}

#if 0
#include<iostream>
using namespace std;

int main()
{
	cout <<"10" << endl;
}
#endif

#if 0
struct bits
{
	//int a : 4;
	char a;
}bits;

int main()
{
	printf("%d\n", sizeof(bits));
	return 0;
}
#endif

//宏定义函数--> 减少了程序调用函数的堆栈开销，使程序运行更快
//并且，将一些无法定义为函数的代码块定义成宏定义函数，使得代码更为简洁
//再有，可以接受任意不同类型的参数，类似于完成了一个简单的函数重载，缺点就是很容易引起系统崩溃