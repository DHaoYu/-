//�̳� ����ʹ���븴�ã������˳���������ԵĵĲ�νṹ��֮ǰ����
//�������ã�C++���п���ʵ����ĸ��á�
#include<iostream>
#include<string>
using namespace std;

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "Peter";
	int _age = 18;
};

class Teacher : public Person
{
protected:
	int _jobid=0;
};

class Student :public Person
{
protected:
	int _stuid=0;
};

int main()
{
	Student s;
	Teacher t;
	Person p;
	s.Print();
	t.Print();
	p.Print();
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	int _a;
protected:
	string _name = "Peter";
	int _age = 18;
private:
	int _b = 0;
};

class Teacher : public Person
{
public:
	void Print()
	{
		cout << _name << _age + 1<< endl;
		//cout << _b << endl;//�����в��ܷ��ʻ����private��Ա
	}
protected:
	int _jobid = 0;
};

int main()
{
	Teacher t;
	t.Print();//
	//t._name;protected private��Ա������������ʡ�
	//protected ��Ա�������п��Ա����ʣ����ǣ�private��Ա���������޷�������
	return 0;
}
#endif

#if 0
//�����������Ը�ֵ���������/����ָ��/���������

class Person
{
public:
	string _name;
	string _sex;
	int _age;
};

class Student :public Person
{
public:
	int _No;//ID
};

int main()
{
	Person p;
	Student s;
	Person p1 = s;//��ֵ
	Person* pp = &s;//ָ��
	pp->_name;//���Է����������л���ĳ�Ա������
	//pp->_No;error �����޷������������еĳ�Ա����
	Person& p2 = s;//����
	//Student s1 = p;error �ᵼ�·���Խ�磬
	//��� ��������a��b������Ա���������������ֶ����һ��c���ͻᵼ�����ɵ�
	//������ָ���д���c�ĵ�ַ�ռ䣬Ϊ�˱������Խ�磬���ԣ�C++ֱ�ӽ�ֹ��������ʽת��
	return 0;
}
#endif 

#if 0
//����̬��
class E
{
public:
	virtual void func(int i = 0)
	{
		std::cout << "E::func()\t" << i << "\n";
	}
};
class F : public E
{
public:
	virtual void func(int i = 1)
	{
		std::cout << "F::func()\t" << i << "\n";
	}
};

void test2()
{
	F* pf = new F();
	E* pe = pf;
	pf->func(); //F::func() 1  �������͸���ˣ�
	pe->func(); //F::func() 0  ��Ŷ������ʲô���������������ĺ�����ȴʹ���˻����в�����Ĭ��ֵ��
	//��Ϊ�����䶯֮����Ϊȱʡ����ֵ���Ǿ�̬�󶨣�Ϊ��ִ��Ч�ʣ��������ڵ����麯��ʱ���п��ܳ���Ԥ��֮�����
	//���顶Effective C++ �����桷 ����37
}

int main()
{
	test2();
	return 0;
}
#endif
//������̬��������ļ̳��еĵ��÷���

class A
{
public:
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
};

class B : public A
{
public:
	/*void func()
	{
		cout << "B::func()" << endl;
	}*/
};

class C : public A
{
public:
	void func()
	{
		cout << "A::func()" << endl;
	}
};

#if 0
int main()
{
	A* pa;
	B* pb = new B();
	C* pnull = nullptr;//pnull��̬����ֱ���ڱ���׶�ָ����C;
	//pnull =(C*)pb;//ָ��B::func() 
	pa = pb;
	//pnull->func();
	pa->func();//��virtual��������ʱ�����ڶ�̬�󶨵����н��е��ã����û��
	//�ú�������ӻ����в��Һ��������е���
	pnull->func();//��ָ���쳣����Ϊ���������ĺ���Ϊ�麯�����麯�����е���
	//��̬�󶨣�����func�ڵ���ʱ��ֻ��������ʱ���ȷ������ʱ����pnullΪ�գ������쳣
	return 0;
}
#endif 
