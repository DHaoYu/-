#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>


using namespace std;

#if 0
//�����
//�ڼ̳���ϵ�У����ؼ̳��Լ����μ̳е��п��ܻ���ڶ��������⣬���ԣ�����
//��̳У�ʹ�ü̳���ϵ�еö���������õ������
//�����ָ�룬���������麯���� 
class B
{
public:
	virtual void func1()
	{
		cout << "B::func1()" << endl;
	}

private:
	int _b=1;
};

class C1 : virtual public B
{
private:
	int _c1 = 2;
};

class C2 : virtual public B
{
private:
	int _c2 = 3;
};

class D : public C1 , public C2
{
public:
	virtual void func1()
	{
		cout << "D::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "D::func2()" << endl;
	}

private:
	int _d = 4;
};

int main()
{
	D d;
	cout << sizeof(d) << endl;
	return 0;
}
#endif

#if 0
//���ָ�루�麯����ָ�룩�����ڴ沼�ֵĵ�һ��λ��_vfptr������麯����ַ
class B
{
public:
	virtual void func1()
	{
		cout << "B::func1()" << endl;
	}

private:
	int _b = 1;
};

class C1 : virtual public B
{
private:
	int _c1 = 2;
};

class C2 :virtual  public B
{
private:
	int _c2 = 3;
};

class D : public C1, public C2
{
public:
	virtual void func1()
	{
		cout << "D::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "D::func2()" << endl;
	}

private:
	int _d = 4;
};

int main()
{
	D d;
	cout << sizeof(d) << endl;
	return 0;
}
#endif

