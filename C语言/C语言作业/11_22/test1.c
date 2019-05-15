#define _CRT_SECURE_NO_WARNNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//void Change(int a[], int b[])
//{
//	int temp = 0;
//	int t = 0;
//	while (t < 10)
//	{
//		temp = a[t];
//		a[t] = b[t];
//		b[t] = temp;
//		t++;
//	}
//	}
//
//
//int main()
//{
//	int a[10] = {0};
//	int b[10] = {1,1,1,1,1,1,1,1,1,1};
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//	Change(&a, &b);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}


//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
//
//int main()
//{
//	int i = 0;
//	double s, sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		s = pow((-1), (i - 1)) / i;
//		sum += s;
//	}
//	printf("sum = %f ", sum);
//	return 0;
//}

//编写程序数一下 1到 100 的所有整数中出现多少次数字9。
//
//void Count()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	Count();
//	return 0;
//}

//==================================================================

//void print(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (j = 1; j <= n; j++)
//	{
//		printf("*");
//		j++;
//		for (i = 1; i <= n; i++)
//		{
//			i++;
//			if (i < j)
//			 printf("**");
//		}
//		printf("\n\n");
//	}
//	for (j = 1; j < n; j++)
//	{
//		j++;
//		printf("*");
//		for (i = 1; i <= n; i++)
//		{
//			i++;
//			if (j < i-2)
//				printf("**");
//		}
//		printf("\n\n");
//	}
//}
//
//int main()
//{
//	int n = 11;
//	print(n);
//	return 0;
//}

//print(int n)
//{
//	for (int j = 1; j <= n/2+1; j++)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			if (2*j > i)
//				printf("*");
//		}
//		printf("\n\n");
//	}
//	for (int j = n/2; j >=1; j--)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			if (2 * j > i)
//				printf("*");
//		}
//		printf("\n\n");
//	}
//}
//
//int main()
//{
//	int n = 11;
//	print(n);
//	return 0;
//}

//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/
//void Narcissistic(int n)
//{
//	int i = 0;
//	int a, b, c;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		a = i / 100;
//		b = i / 10;
//		b = b % 10;
//		c = i % 10;
//		sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
//		if (i == sum)
//			printf("%d  ", i);
//	}
//}
//
//int main()
//{
//	int n = 999;
//	Narcissistic(n);
//	return 0;
//}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//void Sum(int i, int n)
//{
//	int j = n, k = n, sum = 0;
//	int M=0, m=0;
//	for (j = n-1; j >= 0; j--)
//	{
//		M = 0;
//		for (k = j; k >= 0; k--)
//		{
//			m = i*pow(10, k);
//			M += m;
//		}
//		sum = sum + M;
//	}
//	printf("%d \n", sum);
//}
//
//int main()
//{
//	int i = 2, n = 5;
//	Sum(i, n);
//	printf("%d \n", 2 + 22 + 222 + 2222 + 22222);
//	return 0;
//}

//完成猜数字游戏。
//void Guess(int n)
//{
//	int a;
//	printf("请输入0-999之内的数字进行猜测>>>>\n");
//	while (1)
//	{
//		printf("请猜测>>>\n");
//		scanf("%d", &a);
//		if (a > n)
//			printf("猜大了，请继续\n");
//		else if (a < n)
//			printf("猜小了，请继续\n");
//		else
//		{
//			printf("猜对了，该数字是：%d", n);
//			break;
//		}
//	}
//}
//int main()
//{
//	Guess(rand()%1000);
//	return 0;
//}

//写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
//int Binary_Search(int n, int arr[])
//{
//	int i = 10, count = 1;
//	int left = 1, right = i;
//	while (left<right)
//	{
//		int mid = (left + right+1) / 2;
//		if (arr[mid-1] > n)
//			right = mid;
//		else if (arr[mid-1] < n)
//			left = mid;
//		else if (arr[mid-1]==n)
//		{
//			printf("找到该数据：%d", arr[mid-1]);
//			return count;
//		}
//		count++;
//	}
//	printf("未找到数据");
//	return count;
//}
//
//int main()
//{
//	int n = 11, count = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	count = Binary_Search(n,arr);
//	printf("\n共查找%d次\n", count);
//	return 0;
//}


//编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
//#include<conio.h>
//int Pass_word(char str[])
//{
//	int i = 0;
//	for (i = 3; i > 0; i--)
//	{
//		printf("\n您还有%d次机会输入密码\n请输入密码>>>",i);
//		char str1[20];
//		char ch;
//		int p = 0;
//		while ((ch = getch()) != '\r')
//		{
//		//	if (ch == 8)
//		//	{	
//		//		putch('\b'); 
//		//		putch('\b');
//		//		putch(' ');
//		//		putch('\b');
//		//		if (p > 0)
//		//			p--;
//		//	}
//			putch('*');
//			str1[p++] = ch;
//		}
//		str1[p] = '\0';
//		//scanf("%s", &str1);
//		int j = 0;
//		for (j = 0; j <= 10; j++)
//		{
//			if (strcmp(str, str1) == 0)
//			{
//				printf("密码输入正确！\n");
//				return 1;
//			}
//			else
//			{
//				printf("\n密码输入错误！");
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char str[] = "00000.dhy";
//	Pass_word(str);
//	//system("pause");
//	return 0;
//}

//编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
//void Exchange()
//{
//	char a;
//	while (1)
//	{
//		fflush(stdin);
//		scanf("%c", &a);
//		if (a>= 65 && a<= 90)
//			printf("%c\n", a + 32);
//		else if (a >= 97 && a <= 122)
//			printf("%c\n", a - 32);
//		else
//			continue;
//	}
//}
//
//int main()
//{
//	Exchange();
//	return 0;
//}

//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//
//void Multiplication(int n)
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			if (j <= i)
//			{
//				printf("%d*%d = %2d  ",i,j,i*j);
//			}
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("请输入需要打印的乘法口诀行数>>>");
//	scanf("%d", &n);
//	Multiplication(n);
//	return 0;
//}
//
////2.使用函数实现两个数的交换。
//
//void Swop(int * a, int * b)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void Swop1(int &a, int &b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10, b = 20;
//	printf("a = %d , b = %d\n", a, b);
//	Swop(&a, &b);
//	printf("a = %d , b = %d\n", a, b);
//	Swop1(a, b);
//	printf("a = %d , b = %d\n", a, b);
//	return 0;
//}
//
////实现一个函数判断year是不是闰年。
//void Leap_year(int n)
//{
//	if (n % 4 == 0 && n % 400 != 0)
//	{
//		printf("yes");
//	}
//	else
//		printf("no");
//}
//
//int main()
//{
//	int y = 1996;
//	Leap_year(y);
//	return 0;
//}

//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//#include <string.h>
//void init(int arr[],int sz)
//{
//	for (int i = 0; i < sz;i++)
//	arr[i] = i;
//}
//void empty(int arr[],int sz)
//{
//	memset(arr, '\0', 4*sz);
//}
//void reverse(int arr[], int sz)
//{
//	int i = sz;
//	for (i = sz-1; i >= sz/2 ; i--)
//	{
//		int temp;
//		temp = arr[sz - i - 1];
//		arr[sz - i - 1] = arr[i];
//		arr[i] = temp;
//	}
//	return arr;
//}
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr,sz);
//	for (i = 0; i <= 9; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	empty(arr,sz);
//	for (i = 0; i <= 9; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	init(arr, sz);
//		reverse(arr,sz);
//	for (i = 0; i <= 9;i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//	return 0;
//}
//
//////实现一个函数，判断一个数是不是素数。
//void Prime_yn(int n)
//{
//	for (int i = 2; i <= n / 2; i++)
//	{
//		if (n%i == 0)
//		{
//			printf("no");
//			return 0;
//		}
//	}
//	printf("yes");
//}
//
//int main()
//{
//	int n = 6;
//	Prime_yn(n);
//	return 0;
//}

//1.递归和非递归分别实现求第n个斐波那契数。
//
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//	return Fib(n - 1) + Fib(n - 2);
//}
//
//void Fib2(int n)
//{
//	int a = 0;
//	int b = 1;
//	for (int i = 1; i < n; i++)
//	{
//		int temp = a;
//		a = b;
//		b += temp;
//	}
//	printf("\n%d", b);
//}
//
//
//int main()
//{
//	printf("%d\n",Fib(5));
//	Fib2(5);
//}



//2.编写一个函数实现n^k，使用递归实现
//
//void Fun(int n, int k)
//{
//	return n*
//}
//
//int main()
//{
//	Fun(2, 49);
//	return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//非递归
//int my_strlen(char* str)
//{
//	assert(str != NULL);
//
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	
//	return count;
//}
//1.自己调自己
//2.必须有出口
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		//*str++;
//		return 1 + my_strlen(str+1);
//	}
//	//else
//	//{
//		return 0;
//	//}
//}
//
//int main()
//{
//	char str[10] = "abcde";
//	printf("%d", my_strlen(str));
//	return 0;
//}
