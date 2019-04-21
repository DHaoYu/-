#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

#if 0
int main()
{
	int* p = (int*)malloc(sizeof(int)* 3);
	memset(p, 0, sizeof(int)* 3);

	return 0;
}
#endif

#if 0
int main()
{
	//����Ԫ�صĿռ�
	int* p1 = new int;
	int* p2 = new int(10);
	//��Ӧ��Ҫ��delete����ɾ��--->����ᵼ���ڴ�й©
	delete p1;
	delete p2;

	//�����ռ�-->����delete[]����ɾ��
	int* p3 = new int[10];
	int* p4 = new int[];

	delete[] p3;
	delete[] p4;

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}
	
	Test(const Test& t)
		:_t(t._t)
	{
		cout << "Test(const Test&):" << this << endl;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}

private:
	int _t;
};

void TestNewDelete()
{
	//new����ռ�+���ù��캯��
	Test* p1 = new Test;
	//delete�ͷſռ�+������������
	delete p1;

	//malloc����ռ䵫��---!δ���ù��캯��
	Test* p2 = (Test*)malloc(sizeof(Test));
	if (nullptr == p2)
		;
	free(p2);//�ͷſռ䵫��--δ������������

	Test* p3 = new Test[10];//����ʮ��������Test�ռ�
	delete[] p3;//���������Ǹ�Test�ռ䣬���Һ���Ŀռ�������
}

int main()
{
	TestNewDelete();
	return 0;
}
#endif

#if 0
#include<stdlib.h>
#include<crtdbg.h>

#define CRTDBG_MAP_ALLOC
//�������ռ����ͷſռ�Ĳ�ƥ���������Ƿ���������

//�����������ͣ��Ƿ�ƥ��ʹ��û��Ӱ��
void TestFunc()
{
	int* p1 = (int*)malloc(sizeof(int));
	delete p1;

	int* p2 = (int*)malloc(sizeof(int));
	delete[] p2;

	int* p3 = new int;
	free (p3);

	int* p4 = new int[10];
	free(p4);

	int* p5 = new int;
	delete[] p5;

	int* p6 = new int[10];
	delete[] p6;
}

int main()
{
	TestFunc();
	_CrtDumpMemoryLeaks();//�ҵ��޷����м�⣿����--->�����ʺã�����
	return 0;
}
#endif

#if 0
#include<stdlib.h>
#include<crtdbg.h>

#define CRTDBG_MAP_ALLOC
//�����н����ڴ���飬һ��Ҫ��new[] �� delete[] ƥ��ʹ��
class Test
{
public:
	Test()
	{
		_ptr = new int[10];
	}

	~Test()
	{
		delete[] _ptr;
		_ptr = nullptr;
	}
private:
	int* _ptr;

};

void TestFunc()
{
	
	//Test* p1 = (Test*)malloc(sizeof(Test));//û�е��ù��캯��
	//delete p1;//����

	//Test* p2 = (Test*)malloc(sizeof(Test));//������û�е��ù��캯��
	//delete[] p2;

	//Test* p3 = new Test;
	//free(p3);//�ڴ�й©--->�ռ��ͷţ����Ƕ����е���Դû�б�����

	//Test* p4 = new Test[10];
	//free(p4);//����+�ڴ�й©

	//Test* p5 = new Test;//����һ��Test��ռ䣬�޷��ͷŶ��
	//delete[] p5;//����

	//Test* p6 = new Test[10];
	//delete p6;//����+�ڴ�й©
}

int main()
{
	TestFunc();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	//~Test()
	//{
	//	cout << "~Test():" << this << endl;
	//}

private:
	int _data;
};

int main()
{
	Test* p1 = new Test;
	delete p1;//�����������δ������delete���ͷſռ䣬���ǲ��������������

	Test* p2 = new Test[10];
	delete[] p2;

	return 0;
}
#endif

