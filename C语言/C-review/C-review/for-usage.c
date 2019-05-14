#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

#if 0
int main()
{
	/*
	int a[10];//在申请空间是，静态数组和局部变量都在栈上申请空间，
	int b[10];//并且会按照数据结构中栈的方式来申请（入栈）
	int i;    //按照a,i的顺序来写（内存中a在下，i在上）如果i的访问越界，
			  //将会出现越界访问错误
	*/
	/*
	int i = 0;//按照先申请i再申请a的方式来写，i入栈较早，会在a的下面，
	int a[10];//数组a在尾部会保留两个int字节空间以防止访问越界，i正好申请在a的
		      //尾部的第三个int处，当i=13时，a[13]正好修改的是i的内容，导致i=0；
			  //从而呈现无限循环的效果,程序同时也因为越界访问崩溃
	*/
	for (i = 0; i < 13; i++)
	{
		a[i] = 0;
		printf("hehe\n");
	}
	return 0;
}
#endif

#if 0
int main()
{
	int i;
	int b;
	int a[10];

	for (i = 0; i < 13; i++)
	{
		a[i] = 0;
		printf("hehe\n");
	}
	return 0;
}
#endif

