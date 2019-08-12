#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
//ģ���ػ�
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	if (IsEqual(p1, p2))
		cout << p1 << endl;
	else
		cout << p2 << endl;
	return 0;
}
#endif

#if 0
template<class T>//�����ĺ���ģ�壨������ڣ����ܽ����ػ���
bool IsEqual(T& left, T& right)
{
	return left == right;
}

template<>
bool IsEqual<char*>(char*& left, char*& right)//�ػ��İ汾
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	if (IsEqual(p1, p2))
		cout << p1 << endl;
	else
		cout << p2 << endl;
	return 0;
}
#endif

#if 0
class T
{
public:
	friend int& operator[](int pos);
	//�±���������ֻ�������ڽ�������
private:
	int val;
};
#endif

#if 0
//��ģ��ƫ�ػ��еĵĲ����ػ��ͽ�һ��ȷ����
template <typename T>
class iterator_traits<T*>
{ 
public: 
	iterator_traits()
	{
		cout << "Data<T1, int>" << endl;
	} 
	~iterator_traits()
	{}
};

int main()
{
	iterator_traits<int*> d;
	return 0;
}
#endif


#if 0

template<typename T>
class iterator_traits<T*>//�����ڿ��д��ڣ�����ֱ�ӽ���ƫ�ػ�
{
public:
	iterator_traits()
	{
		cout << "ģ��ƫ�ػ����ػ�����ָ��" << endl;
	}

	~iterator_traits()
	{

	}
};

int main()
{
	iterator_traits<int*> i;
	return 0;
}
#endif

#if 0
template<class T>//���в����ػ�ʱ����Ҫ��д�����ԭģ���ࣨģ�巺�������ڽ����������У������ػ�
class Data
{
public:
	Data()
	{
		cout << "!!!" << endl;
	}
private:

};

template <typename T>
class Data<T*>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}
	~Data()
	{}
};

int main()
{
	Data<int*> d;
	return 0;
}
#endif