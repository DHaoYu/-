#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>

using namespace std;

//���string��ǳ��������

#if 0
//��ͳ��ʽʵ��string�����
class String
{
public:
	String(const char* str="")
		//:_str(new char[strlen(str) + 1])//�������ַ���δnullptrʱ��
		//�޷���������ռ䣬���Գ�ʼ������ռ�ֻ�ܷ��ں������ڲ�����
	{
		if (nullptr == str)
		{
			assert(str);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		if (_str != s._str)
		{
			strcpy(_str, s._str);
		}
		else
			return;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}

	~String()
	{
		if (_str)
			delete[] _str;
		_str = nullptr;
	}
private:
	char* _str;
};
/* error
String& operator=(const String& s)
{
	//if (_str != s._str)
	//{
	//	_str = new char[strlen(s._str) + 1];
	//	strcpy(_str, s._str);
	//}

	return *this;
}
*/
void TestString()
{
	String s1;
	String s2("hello");
	String s3(s2);

	String s4("bit");
	s3 = s4;
	String s5(nullptr);
}

int main()
{
	TestString();
	return 0;
}
#endif

//�ִ���ʽʵ�����
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String sTemp(s._str);
		swap(sTemp._str, _str);
	}

	String& operator=(String s)
	{
		_str = nullptr;
		swap(s._str, _str);
		return *this;
	}

	~String()
	{
		if (nullptr != _str)
			delete[] _str;
		_str = nullptr;
	}
private:
	char* _str;
};

void TestString()
{
	String s1;
	String s2("hello");
	String s3(s2);

	String s4("bit");
	s3 = s4;
	String s5(nullptr);
}

int main()
{
	TestString();
	return 0;
}