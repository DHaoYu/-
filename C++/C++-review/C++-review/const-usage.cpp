#include<iostream>
#include<stdio.h>
using namespace std;

#if 0
//const���峣��
int main()
{
	const int val1 = 10;//
	//val1 = 100;error const data
	int const  val2 = 20;
	//val2 = 10;error const data
	//extern const int val = 100;--->???

	return 0;
}
#endif

#if 0
int main()
{
	const int val = 10;//��Ԥ����׶ν����������б���val�������޸�-->ֱ�Ӹ�Ϊ����
	cout << val << endl;
	int* pval = (int*)&val;
	*pval = 100;
	cout << val << endl;
	cout << *pval << endl;//pval ����const����	
	return 0;
}
#endif

#if 0
//ָ��ʹ��const

int main() 
{
	int val1 = 10;
	int val2 = 20;
	int const* p1 = &val1;
	const int* p2 = &val1;
	int* const p3 = &val1;
	const int* const p4 = &val1;
	*p1 = 100;//error non-const pointer , const data
	p1 = &val2;
	*p2 = 100;//error non-const pointer , const data
	p2 = &val2;
	*p3 = 100;
	p3 = &val2;//error const pointer , non-const data
	
	*p4 = 100;
	p4 = &val2;//error const pointer , onst data

	return 0;
}
#endif

#if 0
//����ʹ��const
int main()
{
	const int a = 10;//const���Ͷ���ֻ����const��������
	const int& ra = a;
	cout << ra << endl;
	int const& rb = a;
	cout << rb << endl;
	//error int& const rc = a; //warning ֱ�ӽ�const�޶��������˺���
	const int* pa = &ra;
	return 0;
}
#endif


//�ں�����ʹ��const
#if 0 //��������
void Test1(const int val)//==int const val
{
	val = 100;
}

void Test2(int const* pa)//== const int* val
{
	int a = 1;
	pa = &a;
	*pa = 100;
}

void Test3(int* const pa)
{
	int a = 1;
	pa = &a;
	*pa = 100;
}
//Test1,2,3 �Ͷ��������const�÷���c��������ͬ
#endif

#if 0
//�������Ͳ�������
void Test1(const int& a)
{
	int b = 20;
	a = 100;//const data
	a = b;// error �޷�������������
}

void Test2(int const& a)
{
	a = 100;
}

int Test3(int& const a)//warning ֱ�Ӻ������޶���
{
	int b = 20;
	a = 100;
	return a;
}
#endif

#if 0
//����ֵ��const�÷�
//һ������£������ķ���ֵΪĳ������ʱ�������������Ϊconstʱ�������ڲ����������ء�
//ͨ������������const���κ����ķ���ֵ����Ϊĳ��������ĳ���������õ����
const int Test1()
{
	int a = 10;
	return a;
}

const int * Test2()// == int const * Test2()
{
	int a = 10;
	int* pa = &a;
	return pa;
}

int* const Test3()
{
	int a = 10;
	int* pa = &a;
	return pa;
}
int const* const Test4()//�����ɽ����޸�
{
	int a = 10;
	int* pa = &a;
	return pa;
}

int main()
{
	int a = 100;
	const int* const pa1 = Test2();
	const int* pa1 = Test2();//������Ҫʹ��const���͵�ָ����н���
	int* pa2 = Test3();//����ָ��ָ�򲻿��޸ĵ�ָ�룬��������ָͨ��������н���
	pa2 = &a;		   //Ҳ���ԸĶ�ָ���ָ�򣨿�����һ�ݵ�ַ���أ�
	
	return 0;
}
#endif

#if 0
class Test
{
public:
/*	Test()
	{
		_a = 10;//error �ڹ��캯���ڲ����г�ʼ��const��Ա
	}*/

	Test()
		:_a(10) //����������const��Աʱ��ֻ���ڳ�ʼ���б������г�ʼ��
	{}
/*	void Func()
	{
		_a = 100;//�޷����޸�
	}*/
private:
	const int _a;//��Ա�������ܱ��޸�
};

int main()
{
	Test t;
	return 0;
}
#endif

#if 0
//const �������г�Ա����
//��ó�Ա�����ǲ����޸������κη�const��Ա�ĺ�����һ��д�ں��������������
class Test
{
public:
	Test()
		: _a(10)
	{}

/*	void Func1()const
	{
		_a = 100; // error �����޸ĵ�ǰ������κγ�Ա����
	}*/

	void Func2(int b = 10)const
	{
		b = 100; // �����޸��βε�ֵ
	}

	void Func3()const
	{}
	void Func4()
	{}
	void Func5()const
	{
		Func3();
		//_a = 100;// error const���͵ĳ�Ա�����޷����ʷ�const���͵ĳ�Ա����
		//Func4();//error const ��Ա�����в��ܵ��÷�const���εĳ�Ա����
	}
private:
	int _a;
};

int main()
{	
	const Test t;
	//t.Func4();//error �����޷����÷�const���͵ĳ�Ա����
	//const���͵Ķ������á�ָ�붼�޷����÷�const���͵ĳ�Ա����
	return 0;
}
#endif

#if 0
//��const����ת��δ��const����
//�����ʺ� ������
int main()
{
	const int a = 10;
	const int* pa = &a;
	int& c = const_cast<int&>(a);
	c = 100;
	cout << a << c << endl;
	return 0;
}
#endif

#if 0
const int& Test()
{
	int a = 10;
	return a;
}

int main()
{
	int b = Test();
	cout << b;
	b = 100;
	cout << b;
	return 0;
}
#endif
