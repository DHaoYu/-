#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;

#if 0
//void Swap(int a, int b)
//{
//	int temp;
//	int temp = a;
//	int a = b;
//	int b = temp;
//}

void Swap(int *pa, int *pb)
{
	int temp;
	temp = (*pa);
	(*pa) = (*pb);
	(*pb) = temp;
}

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a - b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap(a, b);//���úʹ�ֵ�Ĵ�ʵ�εķ�ʽ����ͬ�ģ����ԣ����غ���������޷�����ʵ��
	Swap(&a, &b);
	Swap(a, b);

	return 0;
}
#endif

#if 0
int& Add(int left, int right)
{
	left = left + right;
	return left;
}

int main()
{
	int &a = Add(10, 20);
	cout << a << endl;
	return 0;
}//--------------->�ʺţ�
#endif


#if 0 
// ע�⣺ ��Ҫ����ջ�ϵĿռ�
// ����������Ϊ����ֵ�� ֻҪ���صı������������ڱȺ�����
int g_a = 0;
int& Add(int& left, int right)
{
	left = left + right;
	return left;
}

int main()
{
	int a = 10;
	int b = 20;
	int& retVal = Add(a, b);
	printf("%d", retVal);

	//Add(100, 200);
	//cout << retVal << endl;
	printf("%d", retVal);
	return 0;
}
#endif

#if 0
#include<time.h>
struct Time
{
	int a[10000];
};

void TestFunc1(Time a)
{}

void TestFunc2(Time& a)
{}

void TestFunc3(Time* a)
{}

int main()
{
	Time a;

	size_t begin1 = clock();
	for (int i = 0; i < 1000000; i++)
		TestFunc1(a);
	size_t end1 = clock();

	for (int i = 0; i < 1000000; i++)
		TestFunc2(a);
	size_t end2 = clock();

	for (int i = 0; i < 1000000; i++)
		TestFunc3(&a);
	size_t end3 = clock();

	cout << "TimeFunc1(int):time " << end1 - begin1 << endl;
	cout << "TimeFunc2(int&):time " << end2 - end1 << endl;
	cout << "TimeFunc3(int*):time " << end3 - end2 << endl;

	return 0;
}
#endif


#if 0
//Ϊʲô����û��ָ�봫�Ŀ�--->�����ʺţ�����
#include <time.h>
struct A
{
	int a[10000];
};

void TestFunc1(A a)
{}

void TestFunc2(A& a)
{}

void TestFunc3(A* a)
{}


void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc3(&a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(int)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

#if 0
void Swap(int& left, int& right)
{
	int temp = 0;
	temp = left;
	left = right;
	right = temp;
}

void Swap(int* left, int* right)
{
	int temp = 0;
	temp = *left;
	*left = *right;
	*right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;

	int& ra = a;
	ra = 20;
	cout << a << " " << b << endl;

	int* pb = &b;
	*pb = 100;
	cout << a << " " << b << endl;
	
	Swap(a, b);
	Swap(&a, &b);
	return 0;
}
#endif

