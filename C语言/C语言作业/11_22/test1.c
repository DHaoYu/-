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


//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
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

//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
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

//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
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

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

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

//��ɲ�������Ϸ��
//void Guess(int n)
//{
//	int a;
//	printf("������0-999֮�ڵ����ֽ��в²�>>>>\n");
//	while (1)
//	{
//		printf("��²�>>>\n");
//		scanf("%d", &a);
//		if (a > n)
//			printf("�´��ˣ������\n");
//		else if (a < n)
//			printf("��С�ˣ������\n");
//		else
//		{
//			printf("�¶��ˣ��������ǣ�%d", n);
//			break;
//		}
//	}
//}
//int main()
//{
//	Guess(rand()%1000);
//	return 0;
//}

//д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
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
//			printf("�ҵ������ݣ�%d", arr[mid-1]);
//			return count;
//		}
//		count++;
//	}
//	printf("δ�ҵ�����");
//	return count;
//}
//
//int main()
//{
//	int n = 11, count = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	count = Binary_Search(n,arr);
//	printf("\n������%d��\n", count);
//	return 0;
//}


//��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
//#include<conio.h>
//int Pass_word(char str[])
//{
//	int i = 0;
//	for (i = 3; i > 0; i--)
//	{
//		printf("\n������%d�λ�����������\n����������>>>",i);
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
//				printf("����������ȷ��\n");
//				return 1;
//			}
//			else
//			{
//				printf("\n�����������");
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

//��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
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

//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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
//	printf("��������Ҫ��ӡ�ĳ˷��ھ�����>>>");
//	scanf("%d", &n);
//	Multiplication(n);
//	return 0;
//}
//
////2.ʹ�ú���ʵ���������Ľ�����
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
////ʵ��һ�������ж�year�ǲ������ꡣ
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

//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
//////ʵ��һ���������ж�һ�����ǲ���������
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

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
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



//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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
//�ǵݹ�
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
//1.�Լ����Լ�
//2.�����г���
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
