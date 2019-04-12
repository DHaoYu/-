#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<malloc.h>
#include<assert.h>
using namespace std;

#if 0
class SeqList
{
public:
	SeqList(int capacity = 3)
	{
		//assert(_array);
		_array = (int *)malloc(sizeof(int)*capacity);
		_capacity = capacity;
		_size = 0;
	}

	~SeqList()
	{
		assert(_array);
		free(_array);
		_capacity = 0;
		_size = 0;
	}

private:
	int *_array;
	int _capacity;
	int _size;
};

int main()
{
	SeqList s;
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str != nullptr)
			free(_str);

		_str = nullptr;
	}

private:
	char *_str;
};


class Person
{
	//在此处会生成默认的构造函数将Person对象构造好
	//并且会生成默认析构函数调用String类中的析构函数将Persin类析构

private:
	String _name;
	String _gender;
	int _age;

};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "")
	{
		cout << "String(const char*):" << this << endl;
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	void PrintString()
	{
		cout << _str << endl;
	}

	~String()
	{
		cout << "~String():" << this << endl;
		if (_str != nullptr)
			free(_str);

		_str = nullptr;
	}

private:
	char *_str;
};

int main()
{
	int a;
	int b = 10;
	int c(b);//将b中的内容进行拷贝放入c中

	//String s1, s2, s3;

	String s4("hello");
	//String s5(" bit");
	String s5(s4);//---->浅拷贝 导致出错//拷贝是对于原对象的一次引用，针对于String对象
				  //在string对象中有——str指针，在用户显示写出的析构函数中
				  //会将该堆中内存块析构两次，所以导致运行析构函数崩溃
	s4.PrintString();
	s5.PrintString();
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "")
	{
		cout << "String(const char* ):" << this << endl;
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String():" << this << endl;
		//free(_str);
		//_str = nullptr;
	}

private:
	char* _str;
};

int main()
{
	int a;
	int b = 10;
	int c(b);

	String s1("hello");
	String s2(s1);   // 拷贝构造函数
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date&):" << this << endl;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019,12,12);
	Date d2(d1);
	
	Date d3(d2);//时间类中进行浅拷贝不会出错，因为空间只在栈上
	//d3 = d2;
}

int main()
{
	TestDate();
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "")
	{
		cout << "String(const char* ):" << this << endl;
		if (nullptr == str)
			str = "";

		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String& s)
	{
		_str = (char *)malloc(strlen(s._str) + 1);

		strcpy(_str, s._str);
		cout << "String(const String&):" << this << endl;
	}

	~String()
	{
		cout << "~String():" << this << endl;
		free(_str);
		_str = nullptr;
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);//在String类中，拷贝构造函数需要显示给出
	return 0;
}
#endif