#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>

using namespace std;

#if 0
int main()
{
	char c = 'c';
	char& rc = c;

	char* pc = &c;
	int ** p = NULL;
	const char&& rrc = 'c';//C++����ֵ���ã�����ֵ���а󶨵����ý�����ֵ����
	return 0;
}
//�������޷�����
/*
int main(int a)
{
	return 0;
}
*/
#endif

//��ֵ���ã����ӱ�������������
#if 0
#include <iostream>
using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
	A(){
		cout << "construct: " << ++g_constructCount << endl;
	}

	A(const A& a)
	{
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}
	~A()
	{
		cout << "destruct: " << ++g_destructCount << endl;
	}
};

A GetA()
{
	return A();
}

int main() {
	A a = GetA();
	return 0;
}
#endif

#if 0
class A
{
public:
	A() 
		:m_ptr(new int(0))
	{ cout << "construct" << endl; }

	A(const A& a)
		:m_ptr(new int(*a.m_ptr)) //����Ŀ������캯��
	{
		cout << "copy construct" << endl;
	}
	~A(){ delete m_ptr; }
private:
	int* m_ptr;
};

A GetA()
{
	return A();
}


int main() {
	A a = GetA();
	return 0;
}
#endif 

#if 0
int main()
{
	char c = 'c';

	char& rc = c;

	char&& rrc = 'c';
	char& rb = 'c';//error
}
#endif

#if 0
#define MaxSize 100
//�궨�壬�곣��
struct SeqList
{
	int array[MaxSize];
	int _size;
};

#define PI 3.14

int main()
{
	int r = 2;
	double s = PI * r * r;
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	(*pa) = 20;

	cout << a << endl;
	cout << *pa << endl;
	return 0;
}
#endif

#if 0
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
//�꺯����������һЩ�������͵ĸ�����
//�꺯�����ڱ��������ֱ�ӽ�������滻
//��Ԥ���������ű��еļ��滻
int main()
{
	int a = 10;
	int b = 10;
	cout << MAX(a, b) << endl;
	cout << MAX(a, b++) << endl; //error��a++�޷�����++ 
	// (a)>(b++) ? (a) : (b++)
	return 0;
}
#endif

#if 0
//��������inline
//�򵥵ĸ������Ǻ궨����ʽ����
//�޷����Ӻ궨����󻯣�Ϊ�˱�����Щȱ�㣬
//������ inline�����inline�������˺궨����ŵ㣬
//����չ�ˣ�inline�Ƴ���Ŀ�ľ��������궨���ȱ�㣬
//ͬʱ�ֺܺõؼ̳��˺궨����ŵ㡣

inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << Add(a, b) << endl;
	return 0;
}
#endif

