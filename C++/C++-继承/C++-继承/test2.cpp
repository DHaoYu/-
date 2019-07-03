#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class A
{
public:
	void Test()
	{
		cout << _a << endl;
	}
protected:
	int _a = 10;
	int _b = 20;
	int _c = 30;
};

class B : public A
{
public:
	//������������г�Ա���ƺ͸����е���ͬ����������£���������ε�
	//�����е���ͬ���Ƴ�Ա���������������ͬ�����أ��ض���
	//AB�е�����Test������δ�������أ���Ϊ��������������ͬһ����������
	void Test()
	{
		cout << _a << endl;
	}
private:
	int _a = 100;
};

int main()
{
	A a;
	B b;
	a.Test();
	b.Test();//����ͬ�����ع�ϵ
	return 0;
}
#endif

#if 0
//�������е�Ĭ�ϳ�Ա����

class Base
{
public:
	Base(int a)//�������в�����Ĭ�ϵĹ��캯��������Ҫ�����������ʽ����
		//��ȫȱʡ�����Ĺ��캯�����������ʽ���ã����������캯������
	{
		_a = a;
	}
protected:
	int _a;
	int _b;
	int _c;
};

class Derive : public Base
{
public:
	Derive(int d)
		:Base(1)
		, _d(d)
	{}
	void Func()
	{
		cout << _a<< _d << endl;
	}

//protected:
	int _d;
};

int main()
{
	Derive d(100);
	Derive* pd;
	Base* pb = new Base(5);
	pd = (Derive*)pb;
	pd->Func();
	d.Func();
	return 0;
}
#endif

#if 0
//�����ģ��
class Base
{
public:
	Base()
	{
		_a = 1;
		_b = 2;
		_c = 3;
	}
protected:
	int _a;
	int _b;
	int _c;
	//char _a;//16�ֽ�
	//int _b;
	//double _c;
	//char _b;//24�ֽ�
	//double _c;
	//int _a;
};

class Derive : public Base
{
public:
	Derive()
	{
		_d = 4;
	}

	void Func()
	{
		cout << _a << _d << endl;
	}
protected:
	int _d;
};

int main()
{
	Base b;
	Derive d;
	cout << sizeof(b)<< " "<< sizeof(d) << endl;
	return 0;
}
#endif 

#if 0
//�̳�������Ĭ�ϳ�Ա����
class Base
{
public:
	Base()
	{
		_a = 1;
		_b = 2;
		_c = 3;
	}

	Base& operator=(Base& b)
	{
		_a = b._a;
		_b = b._b;
		_c = b._c;

		return  *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _a;
	int _b;
	int _c;
};

class Derive : public Base
{
public:
	Derive()
	{
		_d = 4;
	}

	Derive& operator=(Derive& d)
	{
		*this = d;
		_d = d._d;
		return *this;
	}

	~Derive()
	{
		cout << "~Derive()"<<endl;
	}

	void Func()
	{
		cout << _a << _d << endl;
	}
protected:
	int _d;
};

int main()
{
	Derive d;//��������������󿽱�����������
	Base b(d);
	//Derive d(b);//error �������û�����󿽱��������������,�������
						//�޷�ǿתΪ��������󣬵��ǻ���ָ�����
	Derive d1 = d;
	Base b1 = d;
	return 0;
}
#endif
