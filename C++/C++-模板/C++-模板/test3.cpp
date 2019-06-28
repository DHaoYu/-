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