#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	//Date()//������ֻ����һ��Ĭ�ϵĹ��캯��������дһ�����캯��
	//{
	//	cout << "Date():" << this << endl;
	//}

	Date(int year = 1999, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << this << endl;
		cout << _year << "-" << month << "-" << _day << endl;
	}

	Date(const Date* d)
	{

	}

	void InitDate(int year = 1990, int month = 1, int day = 1)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019,12), d2(0);//���ù��캯��//����ʵ�ε�ʱ��Ὣʵ�ΰ��մ����ҵ�˳��
	d1.InitDate();//���ú���
	Date d3(d1);//���ÿ������캯��
	Date d4();//Ϊ��������d4Ϊ������
	//cout << d1 << endl;--->��Ҫ������������
	return 0;
}
#endif

#if 0
class Date
{
public:
	//
	Date()//���캯��ֻ����һ��������������ᷢ����
	{}
	//Ĭ�Ϲ��캯��Ҳ�����޲ι��캯��

	//ȫȱʡ���캯��
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1999, 12, 12);//���캯���ڶ������������ֻ����һ��
	Date d2;//d2�޷�ʶ��Ӧ�ý����Ǹ����캯�����г�ʼ��
	return 0;
}
#endif

#if 0
class SeqList
{
public:
	SeqList(int capacity = 3)
	{
		_array = (int*)malloc(sizeof(int)*capacity);
		_capacity = capacity;
		_size = 0;
		cout << "SeqList(int):" << this << endl;
	}

	~SeqList()//Ĭ����������ֻ�ܶ�����������������ݽ�����
			  //���޷��Զ�����ָ��ָ������ݽ�������
	{}
	//����������Ķ����û���Ҫ�Լ���������������������
private:
	int *_array;
	int _size;
	int _capacity;
};

void TestFunc()
{
	SeqList s;
}
int main()
{
	return 0;
}
#endif

//void operator<<(ostream& _cout)
//{
//	_cout << _year;
//	_cout << _month;
//	_cout << _day;
//}
#if 0
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& This);
	void InitDate(int year = 2019, int month = 9, int day = 28)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year;
	_cout << d._month;
	_cout << d._day;
	return _cout;
}

int main()
{
	Date d;
	d.InitDate();
	//d << cout;
	cout << d;
	return 0;
}
#endif
