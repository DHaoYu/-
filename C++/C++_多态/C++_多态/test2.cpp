#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
//final���εĻ����麯�����ܱ���������д
class Car
{
public:
	virtual void Drive()final
	{
		cout << "Car" << endl;
	}

	virtual void Buy() 
	{
		cout << "Car" << endl;
	}
};

class Benz : public Car
{
public:
	/*
	virtual void Drive()//error �ڻ������Ѿ���ֹ��������д�麯��
	{
		cout << "Benz" << endl;
	}
	*/
	virtual void Buy() override
	{
		cout << "Car" << endl;
	}
};


int main()
{

	return 0;
}
#endif

#if 0
class Base//�����е����ָ���ŷ�ʽ������
{
public:
	virtual void Func1()//�����麯����˵��������һ��_vfptrָ����ڶ����ڲ���
		//_vfptr���ܷ���ǰ�棬Ҳ���ܷ��������ģ�ͺ��棬�������ƽ̨������v-virtual/f-function��
	{
		cout << "Func1()" << endl;
	}
	//���ָ�����麯���ĵ�ַ���麯����Ҳ������
private:
	int _b = 1;//int ռ��4���ֽ�
	char _c = 'a';//Ҫ�����ڴ����
};

int main()
{
	Base b;
	cout << sizeof(Base) << endl;
	return 0;
}
#endif

#if 0
//�����������ָ���ŷ�ʽ������
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}

	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}

	void func3()
	{
		cout << "Base::func3()" << endl;
	}

private:
	int _b = 1;
	char _c;
};

//�������ڴ���Σ�_vfptrΪ���ָ������ڶ����У��麯������ͨ�������ƴ����ڴ����
//�麯�������Ǵ���麯�����ʵ�ַ��ָ�����飬�����������nullptr
class Derive : public Base
{
public:
	virtual void func()//func����д�ˣ�������Derive�н��������д�ĺ���func��ַ
	{
		cout << "Derive::func()" << endl;
	}
	//func2����������û�б���д���������ڲ����Ǵ�ŵĻ����е�func2�ĺ�����ַ
	
	//���������Լ�������麯���ĺ�����ַ�������������
	virtual void Func()
	{
		cout << "DeriveofBaseFunc" << endl;
	}

	//Base�е�func3Ҳ���̳������ˣ�����û��virtual���Σ���������ͨ��������������д
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	cout << sizeof(b) << sizeof(d) << endl;
	return 0;
}
#endif


#if 0
//��̬ʵ��ԭ���ǰ��ն�̬�����ͣ����û���ָ��������ã��Ӷ�ʵ�ֵ�
//�����ڼ䣬���ĵ��÷�ʽ
class Base
{
public:
	virtual void func()
	{
		cout << "Base::func()" << endl;
	}

	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}

	void func3()
	{
		cout << "Base::func3()" << endl;
	}

private:
	int _b = 1;
	char _c;
};


class Derive : public Base
{
public:
	virtual void func()
	{
		cout << "Derive::func()" << endl;
	}

	virtual void Func()
	{
		cout << "DeriveofBaseFunc" << endl;
	}

private:
	int _d = 2;
};

void Func1(Base& b)
{
	b.func();
	b.func2();
	b.func3();
}

void Func2(Derive& d)
{
	d.Func();
	d.func();
	d.func2();
	d.func3();
}

int main()
{
	Base b;
	Derive d;
	Func1(b);
	Func1(d);//Derive ��û����дfunc2--���û��ࡢ��д��func--�����Լ��ġ�func3Ϊ�̳еĺ���
	Func2(d);
	//Func2(b);//������Ա���--�޷���������
	return 0;
}
#endif