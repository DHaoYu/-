#define _CRT_SECURE_NO_WARNNINGS 1

//��ֵ���ݹ���
//ͬ������  �ڻ���������о�����ͬ���Ƶĳ�Ա��������������
//���ض��壩���������Ķ�����������ͬ���Ƶĳ�Ա����Զ���ʵ��������еĳ�Ա
//			��ͬ���Ƶĳ�Ա������ͬ������

/*Ĭ�ϳ�Ա����
1. ��������в�����Ĭ�ϵĹ��캯��������������Ҫ��ʽ�������캯��
2. �����������Ĭ�ϵĹ��캯�����޲Σ�������������Բ��������캯����ʹ��Ĭ�ϵģ�
3. �������еĹ��캯�������ʼ���б��е���
*/


#if 0
class Base
{
public:
	Base(int b)
	{}
private:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
		:Base(2)
	{}
private:
	int _d;
};

int main()
{
	Derived d1;
	Derived d2;
	d1 = d2;
}
#endif

#include<iostream>
using namespace std;

#if 0
class Father
{
public: // ����Ȩ��
	void FatherFunc()
	{
		cout << "i am father" << endl;
	}
protected: //����Ȩ��
	int _a;
};

class Child : public Father
{
public: //����Ȩ��
	void ChildFunc()
	{
		cout << "i am child" << endl;
	}
protected: //����Ȩ��
	int _b;
};

int main()
{

}
#endif

#if 0
struct Base
{
	int _a = 10;
};

struct Derived : public Base
{
	int _b = 20;
};

int main()
{
	Derived d;
	cout << d._a << d._b << endl;
	return 0;
}
#endif

#if 0
class Base
{
public:
	int _a = 10;
	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

class Derived : public Base
{
public: //Ϊ�˷���������ֱ�ӵ��ã�����Ϊpublic
	int _b = 20;
	//int _a = 100; //������е�_aͬ������ֵ��ͬ
	~Derived()
	{
		Base::~Base();
		_a = 200;
		cout << "~Derived"<< this << endl;
		cout << "a = " << _a << endl;
	}
};

int main()
{
	Base b;
	Derived d;
	cout << "Base: _a = " << b._a << endl;
	cout << "Derived: _a = " << d._a << endl;
}
#endif

#if 0
//��Ԫ��ϵ���ܱ��̳У���Ϊ��Ԫ��ϵ��������ĳ�Ա���̳�ֻ�Ǽ̳л���ĳ�Ա
//��̬��Ա�������Ա��̳���ȥ�������������㾲̬����
class Base
{
private:
	int _b = 10;
	//friend void TestFunc();
public:
	static int _count;
	Base()
	{
		cout << "Base" << this << endl;
	}

	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

int Base::_count = 0;

class Derived : public Base
{
private:
	int _d;
public:
	Derived() :Base()
	{
		_count++; // ��̬��Ա���Լ̳���ȥ
		cout << "Derived" << this << endl;
	}
};
/*
void TestFunc()
{
	Base b;
	b._b = 200;//���Խ����޸�
	cout << b._b << endl;
	Derived d;
	//d._d = 100;//��Ԫ��ϵû�б��̳У� �޷���testfunc�н����޸�
	//cout << d._d << endl;
}
*/
int main()
{
	//TestFunc();
}
#endif

#if 0
//���һ�����ܱ��̳е���
//C++98�����캯�����Ϊ˽�е�,���һ��get(��������)�Ľӿڣ�����ӿ���Ҫ�Ǿ�̬��
//�������ͨ��Ա������������Ҫͨ��������ã������޷���������ͨ���ã����ԣ���Ҫstatic

class Base
{
private:
	int _b;
	Base()
	{
		cout << "Base" << this << endl;
	}

	~Base()
	{
		cout << "~Base" << this << endl;
	}
};

//C++11 final�ؼ���
class Base final //final�ؼ��ֱ�־�̳�
{

};
#endif

