#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;


#if 0
//������ȡ

template<class T>
struct TypeTraits
{
	static bool IsPODType()
	{
		return false;
	}
};

template<>
struct TypeTraits<int>
{
	static bool IsPODType()
	{
		return true;
	}
};

template<>
struct TypeTraits<double>
{
	static bool IsPODType()
	{
		return true;
	}
};

template<>
struct TypeTraits<char>
{
	static bool IsPODType()
	{
		return true;
	}
}; 

template<>
struct TypeTraits<short>
{
	static bool IsPODType()
	{
		return true;
	}
}; 

template<>
struct TypeTraits<unsigned>
{
	static bool IsPODType()
	{
		return true;
	}
};

template<class T>
void CheckTypeTraits(T& t)
{
	cout << t << "��POD���ͣ�" << TypeTraits<T>::IsPODType() << endl;//������ȡ����
}

int main()
{
	int a = 1;
	char b = '2';
	short c = 3;
	float d = 4.4;  //û���ػ�����,��˷���0
	CheckTypeTraits(a);
	CheckTypeTraits(b);
	CheckTypeTraits(c);
	CheckTypeTraits(d);
	return 0;
}
#endif

//ģ��������
#include"test5.h"

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
