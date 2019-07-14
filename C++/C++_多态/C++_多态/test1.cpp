#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
//ʵ��һ��person�࣬ʵ����Ʊ����
class Person
{
public:
	void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student : public Person
{
public:
	void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
	}
};

void TestFunc(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person P;
	Student S;
	P.BuyTicket();
	S.BuyTicket();
	TestFunc(P);
	TestFunc(S);//���д��Σ�TestFunc�����в����������ǻ������ͣ������ڴ�������
				//����о�̬�󶨵������ڳ�Ա����������Student����Person���Ա����
	return 0;
}
#endif

#if 0
//Ϊ��ʵ�ֶ�̬�����������Ҫ�������������н�������Ϊ�麯��
class Person
{
public:
	virtual void BuyTicket()//�麯��ʹ�õİ������Ƕ�̬��
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student : public Person
{
public:
	//�麯����д������������һ������������ȫ��ͬ���麯�������Ǿͳ��������е�
	//�麯����д�˻����е��麯������ȫ��ָͬ��������������������ֵ����ͬ��
	void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
	}
};

void TestFunc(Person& p)
{
	p.BuyTicket();//�ڵ���ʱ���Ƚ����ж϶�̬��������ʲô��Ȼ���ڽ������ڳ�Ա�����ĵ���
}

int main()
{
	Person P;
	Student S;
	TestFunc(P);
	TestFunc(S);

	return 0;
}
#endif

#if 0
//�麯����д��Э��
//Э�䣺����д���麯���У�����ֵ���Բ�ͬ�����Ǳ���ֱ��ǻ����ָ����������ָ�룬
//��������
//������������Ļ����������Ҳ������������Ļ����������
class A
{};

class B : public A
{};

class Person
{
public:
	virtual A* Func()
	{
		cout << "return new A" << endl;
		return new A;
	}

	virtual B* Func2()
	{
		cout << "return new A" << endl;
		return new B;
	}

	virtual Person& Func1()
	{
		cout << "return Person&" << endl;
			return *this;
	}
};

class Student : public Person
{
public:
	virtual B* Func()
	{
		cout << "return new B" << endl;
		return new B;
	}

	/*virtual A* Func2()//error �Ȳ���Э���ֲ����麯����д�����Ա���
	{
		cout << "return new A" << endl;
		return new A;
	}*/

	virtual Student& Func1()
	{
		cout << "return Student&" << endl;
		return *this;
	}
};

void TestFunc(Person& p)
{
	p.Func();
	p.Func1();
}

int main()
{
	Person p;
	Student s;
	TestFunc(p);
	TestFunc(s);
	return 0;
}
#endif

#if 0
//��д��ʽ��һ�㽫��淶��
//���������У���д���麯��ǰ���Բ���virtual���Σ�Ҳ���Թ�����д����Ϊ�̳к������麯��
//���̳��������������������ɱ���ԭ�е����ԣ�ֻ�ǽ�������д�������ǲ��淶��

class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫ��" << endl;
	}
};

class Student : public Person
{
public:
	void BuyTicket()//���淶д��������ǰ�����virtualʹ��淶��
	{
		cout << "���" << endl;
	}
};
#endif

#if 0
class Person
{
public:
	~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	~Student()
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	Person P;
	Student S;
	//P.~Person();
	//S.~Student();
	return 0;//����������������е���
}
#endif

#if 0
//������������д�������е���������������麯�������������������������д�˻����
//������������Ȼ���ǵĺ�������ͬ�����ǣ����������Ϊ������������������������Ĵ���
//����󣬽���ͨһ������������   *�����е������������д���麯��*
class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	~Student()
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;//������಻����virtual�����Ļ��������ھ�̬�󶨣����ܴ�������

	delete p1;
	delete p2;
	return 0;
}
#endif




