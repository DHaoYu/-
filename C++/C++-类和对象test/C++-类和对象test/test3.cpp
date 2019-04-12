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
	//�ڴ˴�������Ĭ�ϵĹ��캯����Person�������
	//���һ�����Ĭ��������������String���е�����������Persin������

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
	int c(b);//��b�е����ݽ��п�������c��

	//String s1, s2, s3;

	String s4("hello");
	//String s5(" bit");
	String s5(s4);//---->ǳ���� ���³���//�����Ƕ���ԭ�����һ�����ã������String����
				  //��string�������С���strָ�룬���û���ʾд��������������
				  //�Ὣ�ö����ڴ���������Σ����Ե�������������������
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
	String s2(s1);   // �������캯��
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
	
	Date d3(d2);//ʱ�����н���ǳ�������������Ϊ�ռ�ֻ��ջ��
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
	String s2(s1);//��String���У��������캯����Ҫ��ʾ����
	return 0;
}
#endif