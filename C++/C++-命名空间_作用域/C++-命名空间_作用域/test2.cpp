#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stdio.h>
using namespace std;


#if 0
//ȫȱʡ�����ĺ���
//��ȱʡ�����ĺ���
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << a << b << c << endl;
}

void TestFunc2(int a, int b, int c = 30)
{
	cout << a << b << c << endl;
}
//��ȱʡ����ֻ�ܽ�ȱʡֵ�����������
//void TestFunc3(int a = 10, int b, int c)
//{
//
//}

int main()
{
	TestFunc1();
	TestFunc1(1, 2, 3);
	TestFunc1(1);
	TestFunc1(1, 2);
	TestFunc1(2, 3);

	TestFunc2(10, 20);
	TestFunc2(1, 2, 3);
	return 0;
}
#endif

#if 0
int g_a = 10;//ȫ�ֱ���

void TestFunc(int a = g_a)
{
	cout << a << endl;
}

int main()
{
	TestFunc();
	TestFunc(100);
	return 0;
}
#endif

#if 0
void TestFunc()
{}

int main()
{
	TestFunc(10);//���ò�������--- = =#�����ʺţ���
	TestFunc(10, 20);
	return 0;
}
#endif

#if 0

//�������أ���������ͬ�������򣬱�������ͬ�ĺ�����
//ֻ�з���ֵ���Ͳ�ͬ�ǹ����ɺ������أ������б���벻ͬ�������������������ͣ��������͵Ĵ���

//�����1.0��2.0����int������������û��������Ӧ���͵����غ���
//ֻ�ǽ�double������ǿ������ת����תΪint��
int Add(int left, int right)
{
	cout << left + right << endl;
	return left + right;
}

//�޷����ؽ�����������ͬ�ĺ���
/*
double Add(int left, int right)
{
	return left + right;
}
*/

double Add(double left, double right)
{
	return left + right;
}


int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	//Add(1, 2.0);//û���ҵ��������ͺ��ʵĺ����������޷�����ƥ��
	return 0;
}
#endif

#if 0
void TestFunc()
{}

void TestFunc(int a)
{}

void TestFunc(int a, int b)
{}

void TestFunc(double a)
{}

//void TestFunc(int b, int a)//���������뺯�������õı��������޹�
//{}

void TestFunc(int a, double b)
{}

void TestFunc(double a, int b)
{}

int main()
{
	return 0;
}
#endif


#if 0
void TestFunc()
{}

void TestFunc(int a = 0)
{}

int main()
{
	TestFunc(10);
	//TestFunc();//�������ʵ��Ϊ�գ������������б���������
	return 0;
}
#endif


#if 0
//C���Ա������Ժ����������εĹ���
//���������������ʺţ�����
int Add(int left, int right);// _Add:�ڱ�������


double Add(int left, int right);//_Add

int main()
{
	return 0;
}
#endif

#if 0
int Add(int left, int right);// 


double Add(int left, int right);

int main()
{
	return 0;
}
#endif

#if 0
//C++�У��������Ժ��������ֵ����ι���
int Add(int left, int right); //(?Add@@YAHHH@Z)
double Add(double left, double right); //(? Add@@YANNN@Z)

double Add(double left, int right);//(?Add@@YANNH@Z)

int main()
{
	Add(10, 20);
	Add(1.0, 2.0);
	Add(1.0, 2);
	return 0;
}
#endif

#if 0
extern "C" double Add(double left, double right);//extern "C" ����C���Ի������б�������
//{
//	return left + right;
//}

int main()
{
	Add(1.0, 2.0);
	return 0;
}
#endif


