#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

//���̳�
//��̳�
//class Ĭ�ϵļ̳з�ʽ��private�� struct Ĭ�ϵļ̳з�ʽΪpublic
#if 0
class Base
{
public:
	int _b = 10;
};

class Derived : Base //classĬ�ϵļ̳з�ʽΪ˽��private�̳�
{
private:
	int _d;
public:
	void Test()
	{
		_b = 100;
		//cout << _b << endl;
	}
};

int main()
{
	Derived d;
	d._b = 100;
	d.Test();
}
#endif

#if 0
struct Base
{
public:
	int _b = 10;
};

struct Derived : Base //structĬ�ϵļ̳з�ʽΪ����public�̳�
{
private:
	int _d;
public:
	void Test()
	{
		_b = 100;
		//cout << _b << endl;
	}
};

int main()
{
	Derived d;
	d._b = 100;
	cout << d._b << endl;
	d.Test();
}
#endif

//���μ̳�

