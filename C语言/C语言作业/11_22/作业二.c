//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//	c = a;
//	a = b;
//	b = c;
//	printf("%d %d\n", a, b);
//	scanf("%d %d", &a, &b);
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("%d %d\n", a, b);
//	return 0;
//}



//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i - 1]>arr[i])
//		{
//			arr[i] = arr[i - 1];
//		}
//		else
//			arr[i] = arr[i];
//	}
//	printf("%d \n", arr[9]);
//	
//	return 0;
//}
//
//
//int main()
//{
//	int a = 0; 
//	int b = 0;
//	int i = 0;
//	printf("请输入两个数字：\n");
//	scanf("%d %d", &a, &b);
//	for (i = a; i >= 1; i--)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			printf("\n%d为两数的最大公约数\n", i);
//			break;
//		}
//	}
//	return 0;
//}
//输入数据有多组，每组数据占一行，每行的第一个正整数n，表示整数个数，后面接n个正整数，当n为0时，不做任何处理输入结束
//输出每组排序的结果 
//#include<stdio.h>
//#include<stdlib.h>
//
//void sort(int a[], int s);
//int main()
//{
//	int i, N;
//	while (scanf("%d", &N))
//	{
//		int *a = (int *)malloc(4);
//		if ( N == 0 )
//			break;
//		else
//		{
//			for (i = 0; i<N; i++)
//			{
//				scanf("%d", a[i]);
//			}
//			sort(a, N);
//			for (i = 0; i < N; i++)
//			{
//				printf("%d ", a[i]);
//			}
//			printf("\n", a[i]);
//		}
//	}
//}
//void sort(int a[], int s)
//{
//	int i, j, x;
//	for (j = 0; j < s ; j++)
//	{
//		for (i = 0; i < s; i++)
//		{
//			if (a[i] > a[i + 1])
//			{
//				x = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = x;
//			}
//		}
//	}
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12; i++)
//	{
//		printf("杨兆吃屎  ");
//		arr[i] = 0;
//	}
//} 
////#include <stdio.h>
//#include <conio.h>
//
//typedef struct
//{
//	int key;
//} RecType;
//typedef struct
//{
//	RecType R[100 + 1];
//	int Length;
//}Sq_list;
//
//void InsertSort(Sq_list *L)
//{
//	int i, j;
//	for (i = 2; i <= L->Length; i++)
//	if (L->R[i].key<L->R[i - 1].key)
//	{
//		L->R[0] = L->R[i];
//		for (j = i - 1; L->R[0].key<L->R[j].key; j--)
//			L->R[j + 1] = L->R[j];
//		L->R[j + 1] = L->R[0];
//	}
//}
//
//void insert(Sq_list *slt, RecType x)
//{
//	int i;
//	if (slt->Length<100 + 1)
//	{
//		i = slt->Length;
//		//		while(i>=0/*&&slt->R[i]>x*/)
//		//		{
//		//			slt->R[i+1]=slt->R[i];
//		//			i--;
//		//		}
//		slt->R[i + 1] = x;
//		slt->Length++;
//
//	}
//}
//
//void display(Sq_list slt)
//{
//	int i;
//	if (!slt.Length)
//		printf("\n顺序表是空的！");
//	else
//	for (i = 1; i<slt.Length+1; i++)
//		printf("%d ", slt.R[i]);
//	printf("\n");
//}
//
//int main()
//{
//	Sq_list L;
//	int a[100], i, j, x, N;
//	RecType M;
//
//	printf("输入顺序表的长度\n");
//	scanf("%d", &N);
//	printf("输入顺序表中元素\n");
//	for (i = 1; i <= N; i++)
//		scanf("%d", &L.R[i].key);
//	L.Length = i - 1;
//	InsertSort(&L);
//	printf("排序后的结果：\n");
//	for (i = 1; i <= N; i++)
//		printf("%d ", L.R[i].key);
//	printf("\n");
//	getch();
//	printf("输入插入的元素：");
//	scanf("%d", &M);
//	insert(&L, M);
//	InsertSort(&L);
//	printf("排序后的结果：\n");
//	display(L);
//}

//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i + 1] > arr[i])
//		{
//			arr[i] = arr[i + 1];
//		}
//		else
//			break;
//	}
//	printf("Max= %d", arr[i]);
//	
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	
//	scanf("%d %d %d", &a, &b, &c);
//	int max = b;
//	if (a > b)
//	{
//		max = a;
//	}
//	if (c > a)
//	{
//		max = c;
//	}
//	printf("Max = %d", max);
//	return 0;
//}


//int main()
//{
//	unsigned char i = 0;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%d\n",i);
//	}
//	return 0;
//}

//
//int main()
//{
//	char arr[20] = { 0 };
//	strcpy(arr, "hello bit");
//	printf("%s", arr);
//	return 0;
//}
//
//int main()
//{
//	char c;
//	scanf("%c", &c);
//	if (c == '1')
//	{
//		printf("1");
//	}
//	else if (c == '2')
//	{
//		printf("2");
//	}
//	return 0;
//}

