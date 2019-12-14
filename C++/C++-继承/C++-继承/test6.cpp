#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>

using namespace std;
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base" << endl;
	}
private:
	int _b;
};

class Derived : public Base
{
public:
	//����Ĭ�ϵ������๹�캯��ʱ��(�����й��캯������������ڣ�����Ϊ��ȫȱʡ)
	//�ڳ�ʼ���б���û���Ĺ��캯��
private:
	int _d;
};

int main()
{
	Derived d;//����Ĭ�ϵ������๹�캯��
	return 0;
}
#endif
#if 0
class Base
{
public:
private:
	int _b;
};

class Derived : public Base
{
public:
private:
	int _d;
};
int main()
{
	Derived d;
	//���������������d������Ĭ�ϵ���������������
}
#endif

#if 0
class Derived; //��Ҫ������������

class Base
{
public:
	friend void print(Base &b, Derived &d);

	//private ��Ա��ʲô��������ⶼ�����ɷ���
protected:
	int _b = 10;
};

class Derived : public Base
{
public:
	friend void print1(Base &b, Derived &d);
protected:
	int _d = 20;
};	

void print(Base &b, Derived &d)
{
	cout << "Base:" << b._b << endl;
	cout << "Derived:" << d._d << endl;//error ��Ϊ��Ԫ������̳�
}
void print1(Base &b, Derived &d)
{
	cout << "Base:" << b._b << endl; // error ��Ϊ��Ԫ������̳�,���ԣ�
									 // �����е���ԪҲ���ܷ��ʻ����еı�����Ա
	cout << "Derived:" << d._d << endl;
}

int main()
{
	Base b;
	Derived d;
	print(b, d);
	print1(b, d);
	return 0;
}
#endif

#if 0
#include<string>
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}
#endif

#if 0
class Base
{
public:
	void PrintBaes()
	{
		cout << static_b << endl;
		//cout << static_d << endl;//error.�����޷������������еľ�̬��Ա����
	}
protected:
	int _b = 10;
	static int static_b;
};
int Base::static_b = 11;//��̬��Ա��ʼ��

class Derived : public Base
{
public:
	void Print()
	{
		cout << static_b << endl;//�������з��ʻ���ľ�̬��Ա
		cout << _d << endl;
	}
protected:
	int _d = 20;
	static int static_d;
};
int Derived::static_d = 12;

int main()
{
	Derived d;
	d.Print();
	return 0;
}
#endif
