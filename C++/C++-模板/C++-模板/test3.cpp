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