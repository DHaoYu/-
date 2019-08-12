#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
//模板特化
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
template<class T>//基础的函数模板（必须存在，才能进行特化）
bool IsEqual(T& left, T& right)
{
	return left == right;
}

template<>
bool IsEqual<char*>(char*& left, char*& right)//特化的版本
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
	//下表访问运算符只能在类内进行重载
private:
	int val;
};
#endif

#if 0
//类模板偏特化中的的部分特化和进一步确定化
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
class iterator_traits<T*>//该类在库中存在，可以直接进行偏特化
{
public:
	iterator_traits()
	{
		cout << "模版偏特化，特化常规指针" << endl;
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
template<class T>//进行部分特化时，需要先写出类得原模板类（模板泛化），在接下来的类中，进行特化
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