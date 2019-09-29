#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;

#if 0
class Date
{
public:
	//Date()//在类中只存在一个默认的构造函数，或者写一个构造函数
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
	Date d1(2019,12), d2(0);//调用构造函数//传输实参的时候会将实参按照从左到右的顺序
	d1.InitDate();//调用函数
	Date d3(d1);//调用拷贝构造函数
	Date d4();//为函数声明d4为函数名
	//cout << d1 << endl;--->需要输出运算符重载
	return 0;
}
#endif

#if 0
class Date
{
public:
	//
	Date()//构造函数只存在一个，否则编译器会发警告
	{}
	//默认构造函数也是午无参构造函数

	//全缺省构造函数
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
	Date d1(1999, 12, 12);//构造函数在对象的生命周期只调用一次
	Date d2;//d2无法识别应该进入那个构造函数进行初始化
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

	~SeqList()//默认析构函数只能对于所创建对象的内容进行析
			  //构无法对对象内指针指向的内容进行析构
	{}
	//对于这种类的对象，用户需要自己给出析构函数进行析构
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
