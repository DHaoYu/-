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