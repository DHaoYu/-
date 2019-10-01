#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#if 0
class Test
{
private:
	char _c1;
	int _a;
};

class T
{
private:
	Test t;
	char _c;
};

int main()
{
	cout << sizeof(T) << endl;//T�������ڴ����

	return 0;
}
#endif

#if 0
class T1
{
public:
	T1(char c = 'c', int b = 1, double a = 1.0)
		:_c(c)
		, _b(b)
		, _a(a)
	{}
	char  _c;
	int _b;
	double _a;
};

class T2
{
public:
	T2(char c = 'c', int b = 1, double a = 1.0)
		:_c(c)
		, _b(b)
		, _a(a)
	{}
	char _c;
	double _a;
	int _b;
};

int main()
{
	T1 t1;
	T2 t2;
	cout << "T1 size is :" << sizeof(T1) << endl;//Ԫ�������е�����˳��ͬ��
	cout << "T2 size is :" << sizeof(T2) << endl;//�����ռ���ڴ��СҲ���ܲ�ͬ

	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;//error ȫȱʡ�������޲εĹ��캯����ΪĬ�Ϲ��캯����ֻ�ܴ���һ��
	return 0;
}
#endif

#if 0
class Test1
{
public:
	void TestFunc()
	{}

	int _data;
};

class Test2
{
public:
	void TestFunc()
	{}

	int _data;
};

int main()
{
	Test1 t1;
	t1.TestFunc();

	Test2 t2;
	t2.TestFunc();

	return 0;
}
#endif

#if 0
class Test
{
public:
	void TestFunc()
	{}
	
	int _data;
};

int main()
{
	Test t;
	t.TestFunc();
	cout << sizeof(Test) << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	explicit Date(int year)
	{
		_year = year;
	}

	
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1999);//���û��explicit���������ڽ�2020��ֵʱ�Ὣ����ʽת��ΪDate
	d1 = 2000;//explicit���ڹ��캯��ǰ����ֹ��ʽ�Ľ�2020(��������)ת��ΪDate������ʱ����
	return 0;
}
#endif

#if 0
//C++11
class T
{
public:
private:
	//static int _count = 0;//error 
	int _a = 0;//��C++11�У��Ǿ�̬��Ա�����ĳ�ʼ������ֱ�ӷ�������ʱ���г�ʼ��
	int b = 0;
	int* array = new int[10];
};

int main()
{
	T t;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{}

	static void TestFuncSta()
	{
		cout << _a << endl;
		//cout << _b << endl;ͬ���޷�������ͨ��Ա����
		//TestFunc1();//error ��Ϊ��ͨ��Ա�����ж�����Ĭ�ϵ�thisָ��
		//��̬��Ա������û��thisָ�룬�����޷�������ͨ��Ա����
	}

	void TestFunc1()
	{
		TestFuncSta();//��ͨ��Ա�������Է��ʾ�̬��Ա������������������
		cout << _a << _b << endl;//��Ա����Ҳ�����Է���
	}

	~Test()
	{}

private:
	static int _a;
	int _b;
};

int Test::_a = 0;

int main()
{
	Test t;
	t.TestFunc1();
	return 0;
}
#endif