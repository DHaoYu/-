#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<string>

using namespace std;

#if 0
//C�����ݺͲ��������Ƿ����
//C++�����ݿ��Ժͺ���ͬʱ����һ���ṹ����

struct People
{
	char _name[20];
	int _age;
	char _gender[5];

	void InitPeople(char* name,int age,char* gender)
	{
		strcpy_s(_name, name);
		_age = age;
		strcpy_s(_gender, gender);
	}

	void PrintPeople()
	{
		cout << _name << "-" << _age << "-" << _gender <<endl;
	}

};

int main()
{
	People p1, p2, p3;
	p1.InitPeople("Peter", 35, "��");
	
	p2.InitPeople("DHaoyu", 20, "��");

	p3.InitPeople("Summer", 5, "��");
	People p4;
	p4.InitPeople("Jingjing", 34, "Ů");

	p1.PrintPeople();
	p2.PrintPeople();
	p3.PrintPeople();
	p4.PrintPeople();
	return 0;
}
#endif

#if 0
//�����Ͷ����������
class People
{
public:
	void InitPeople(char* name ,int age,char* gender)
	{
		strcpy_s(_name, name);
		_age = age;
		strcpy_s(_gender, gender);
	}

	void PrintPeople()
	{
		cout << _name << "-" << _age << "-" << _gender << endl;
	}

private:
	char _name[20];
	int _age;
	char _gender[3];
};

int main()
{
	People p1;
	p1.InitPeople("������", 20, "��");
	p1.PrintPeople();
	//p1._age = 20;
	cout << sizeof(p1) << endl;
	return 0;
}
#endif

#if 0
class Test1
{
public:
	void Testclass()
	{}

	int _a;
	char _b;
};

class Test2
{
public:
	void Testclass()
	{}

	char _b;
};

class Test3
{
};

//���С�ļ��㷽ʽ��ṹ����ͬ
//��Ҫ�����ڴ����

int main()
{
	cout << sizeof(Test1) << endl;
	cout << sizeof(Test2) << endl;
	cout << sizeof(Test3) << endl;//������ֽ���Ϊ1
	cout << offsetof(Test2, _b) << endl;
	cout << offsetof(Test1, _b) << endl;
	return 0;
}
#endif

#if 0
//����thisָ��
//thisָ����C++�������Ǵ���һ��ָ��������޷������ض��壨�޸ģ�
//
struct People
{
	char _name[20];
	int _age;
	char _gender[3];
};

void InitPeople(People *p,char *name, int age,char *gender)
{
	strcpy_s(p->_name, name);
	p->_age = age;
	strcpy_s(p->_gender, gender);
}

void PrintPeople(People *p)
{
	cout << p->_name << "-" <<p-> _age << "-" <<p->_gender << endl;
}

int main()
{
	People p1;
	InitPeople(&p1, "Peter", 35, "��");
	PrintPeople(&p1);
	return 0;
}
#endif

#if 0
class People
{
public:
	void InitPeople(char *name, int age, char *gender);
	
	//void InitPeople(char *name, int age, char *gender)
	//{
	//	strcpy_s(_name, name);
	//	_age = age;
	//	strcpy_s(_gender, gender);
	//}
	void PrintPeople();

//private:
	char _name[20];
	int _age;
	char _gender[3];
};

void People::InitPeople(char *name, int age, char *gender)
{
	strcpy_s(_name, name);
	_age = age;
	strcpy_s(_gender, gender);
}

void People::PrintPeople()
{
	cout << _name << "-" << _age << "-" << _gender << endl;
}

int main()
{
	People p;
	p.InitPeople("Peter", 35, "��");
	//p.InitPeople("Peter", 35, "��");
	p.PrintPeople();
	return 0;
}
#endif

#if 0
class A
{
public:
	void TestFunc1()
	{
		cout << this << endl;
		this->_a = 20;
		cout << _a << endl;
	}

	void TestFunc2()
	{
		cout << this << endl;
		this->_a = 10;
		cout << _a << endl;
		this->TestFunc1();
	}

protected:
	int _a;
};

int main()
{
	A t;
	//A *p = nullptr;//��ָ�룬�޷�ָ���κ��ڴ�
	A *ps = &t;//ָ�벻Ϊ�գ����Խ���ָ��
	//p->TestFunc1();
	cout << ps << endl;
	ps->TestFunc1();
	//t.TestFunc2();

	return 0;
}
#endif

#if 0 
//���ڴ���--->��ָ���޷�ָ���������
class A
{
public:
	void TestFunc1()
	{
		cout << this << endl;
		this->_a = 20;
		cout << "TestFunc()" << endl;
	}

	void TestFunc2()
	{
		this->_a = 10;
	}

protected:
	int _a;
};


int g_a = 10;

int main()
{
	cout << g_a << endl;
	A* ps = nullptr;
	ps->TestFunc1();// TestFunc1(ps)
	return 0;
}
#endif

#if 0
class Test
{
public:
	void TestFunc()
	{
		cout << this << endl;
		Test* const &p = this;//�����const��һ�����������ã�������ñ��������޸ģ�
		//��Ӧ��thisҲҪ���޸ģ�����this�޷��޸ģ�������Ҫ����const
		//cout << _a << endl;
		cout << &p << endl;
	}

private:
	int _a;
};

int main()
{
	Test t;
	t.TestFunc();
	Test* p = &t;
	Test* &q = p;//����

	cout << p << endl;
	cout << q << endl;

	cout << &p << endl;
	cout << &q << endl;
	return 0;
}
#endif

