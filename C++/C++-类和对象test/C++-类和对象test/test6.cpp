#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
//���������ܹ������˶��ٸ�����-->��Ҫ����ȫ�ֱ���
//���ܽ�����������ÿ�������У�Ӧ�������ж�����
//1.ʹ��ȫ�ֱ���--->ȱ�ݣ�����ȫ

class Test
{
public:
	Test()
		:_a(0)
		//, _count(0)--->�������ڴ˴����г�ʼ������Ҫ����������г�ʼ��
	{
		_count++;
	}

	Test(Test& t)
	{
		_count++;
	}


	~Test()
	{
		_count--;
	}
private:
	int _a;
	static int _count;
};

int Test::_count = 0;//  -----  ���� ��Ҫ������������

int main()
{
	Test t1, t2;
	Test t3(t1);
	
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test()
		:_a(1)
	{
		cout << "Test():" << this << endl;
	}

	//��ͨ��Ա��������thisָ�룬���Է�����ͨ��Ա�����Լ��Ǿ�̬��Ա����
	int Getprivate()
	{
		return _a;
	}

	static int Getstatic()//��̬��Ա����������thisָ�룬���ܷ�����ͨ��Ա����
	{
	//	Getprivate();//error �޷�����
		return _count;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

//	static int _count;����public�н�����һ���Ĵ���

private:
	int _a;
	static int _count;
};

//int Test::_count = 0;//��ʼ��������ⲿ����

int main()
{
	Test t;
	cout << t.Getprivate() << endl;
	cout <<Test::Getstatic() << endl;///���ʾ�̬��Ա��������������ÿռ�
	return 0;
}
#endif


#if 0
class Time
{
	friend void Testfriend();
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << _hour << endl;
	}



private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
	friend ostream& operator<<(ostream& cout,const Date& d);

public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int ,int ,int ):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	void operator<<(ostream& cout)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}


	friend void Testfriend();

private:
	int _year;
	int _month;
	int _day;
};

void Testfriend()
{
	Time t;
	t._hour = 16;

	Date d;
	d._year = 2019;
}

//����
//1. ��������������һ��Ϊostream�����ã�����Ҫ���������
//2. ����Ҫ�з���ֵ����ȷ�����Խ����������
//3. �����������������ٽ��л��в��������Ծ���������
//4. �ú����������Ϊ�����Ԫ����---�����б������ó�Ϊ��Ԫ
ostream& operator<<(ostream& cout,const Date & d)
{
	cout << d._year << "-" << d._month << "-" << d._day;
	return cout;
}

int main()
{
	Date d(2018, 4, 14);
	d.PrintDate();

	d.operator<<(cout);//����������������������ڽ��У��ᵼ��
	//��������ߵ������ԣ��������������������������
	//d << cout;

	//��Ҫ���䶨��Ϊ���е���Ԫ����
	cout << d << endl;
	return 0;
}
#endif

#if 0
class Time
{
	friend class Date;//���Ƶ�
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << this->_hour << endl;
	}

	void TestFriendClass()
	{
		Date d;
		d._year = 2019;
	}

private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
	friend class Time;//��ÿһ�����ж�������Ϊ����һ�������Ԫ�࣬
					  //��֤���������õĽ�������
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}
#endif