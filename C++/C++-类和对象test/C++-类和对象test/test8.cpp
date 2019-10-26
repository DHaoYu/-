#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	Date()//���캯��
	{
		//...
	}

	Date(Date d)//�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;//���ù��캯��
	Date d2(d1);//���ÿ������캯��
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)//ȫȱʡ���캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date* operator&()
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;//���ù��캯��
	Date d2 = d1;//���ÿ������캯��
	d2 = d1;
	Date* pd = new Date();
	return 0;
}
#endif

#if 0
class String
{
public:
	String(char* str = "hello world")//���캯��
		:_str(str)
	{}
	~String()
	{
		free(_str);
	}
private:
	char* _str;
};

int main()
{
	String s1;
	String s2(s1);
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 2019, int month = 10, int day = 19)//���캯��
		:_year(year)
		,_month(month)
		, _day(day)
	{
	}
	Date(Date& d)//�������캯��
		:_year(d._year)//��ʼ���б�
		,_month(d._month)
		,_day(d._day)
	{
	}
private:
	int _year;
	int _month;
	int _day;
};
#endif

#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};

class B
{
public:
	B(A ca, int ref, int b)
		:_ca(ca)
		,_ref(ref)
		,_b(b)
	{}
private:
	A _ca;
	int& _ref;
	const int _b;
};

int main()
{
	B b(1, 2, 3);
	return 0;
}
#endif

#if 0
class B
{
public:
	B()
	{
	}
private:
	static int _s;
};

int B::_s = 10;// ��������г�ʼ����̬��Ա����

int main()
{
	B b;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int a, int b) :_a(a), _b(b)
	{
	}
private:
	int _a;
	int _b;
};

int main()
{
	B b1(1, 2);
	b1 = 20;
	return 0;
}
#endif

#if 0
class B
{
public:
	static void Func()
	{
		_a = 10;
	}
private:
	int _a;
};

int main()
{
	B b;
	b.Func();
}
#endif

#if 0
class B
{
public:
	void print()
	{
		cout << _a << _b << _c << endl;
	}
private:
	int _a = 10;
	char _b = 'A';
	double _c = 1.1;
};

int main()
{
	B b1, b2;
	b1.print();
	b2.print();
	return 0;
}
#endif

#if 0
class A
{
private:
	int _c = 10;
};

class B
{
public:
	void print()
	{
		cout << _a << _b << _c << endl;
	}
private:
	static int _a = 1;
	A a;
};

int main()
{
	B b1, b2;
	b1.print();
	b2.print();
	return 0;
}
#endif