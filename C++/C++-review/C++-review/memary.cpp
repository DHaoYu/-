#define _CRT_SECURE_NO_WARNINGS 
#if 0
#include<iostream>

using namespace std;

int globalVar = 1;
static int staticGlobalVar = 2;

void Func()
{
	static int staticVar = 3;
	int localVar = 4;

	int arr[10] = { 1, 2, 3, 4 };
	char ch[] = "abcd";
	char* pch = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}
int main()
{
	return 0;
}
#endif

#if 0
int main()
{
	int* ptr1 = new int;//��̬����һ��int��С�Ŀռ�
	int* ptr2 = new int(5); 
	//��ptr2ָ����ָ��Ŀռ��е�ֵ��ʼ��Ϊ5
	int* ptr3 = new int[4];//��̬����������4��int��С�Ŀռ�

	ptr3[1] = 1;//��������ʹ�ý��н����õ�
	ptr3[2] = 2;
	//��ȻҲҪ�����ͷ�
	delete ptr1;
	delete ptr2;
	delete[] ptr3; //�����Ŀռ���Ҫ����[]�����ͷ�
	return 0;
}
#endif

#if 0
#include<stdio.h>

int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", arr+i);
	}
	int max = arr[1];
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("%d", max);
}
#endif

#if 0
int main()
{
	int* ptr1 = new int;//��̬����һ��int��С�Ŀռ�
	int* ptr2 = new int(5);
	//��ptr2ָ����ָ��Ŀռ��е�ֵ��ʼ��Ϊ5
	int* ptr3 = new int[4];//��̬����������4��int��С�Ŀռ�

	ptr3[1] = 1;//��������ʹ�ý��н����õ�
	ptr3[2] = 2;
	//��ȻҲҪ�����ͷ�
	delete ptr1;
	delete ptr2;
	delete[] ptr3; //�����Ŀռ���Ҫ����[]�����ͷ�
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Test
{
public:
	Test()
		:data(10)
	{
		cout << "Test()" << this << endl;
	}
	Test(int _data)
		:data(10)
	{
		cout << "Test()" << this << endl;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int data;
};

void func1()
{
	Test* iptr1 = new Test; //����Ĭ�ϵĹ��캯��������û���ʽ������
	//��û��Ĭ�Ϲ��죬������
	Test* iptr2 = new Test(10); //���ô��в����Ĺ��캯��
	delete iptr1;
	delete iptr2;
}

int main()
{
	//func1();
	int* pint = new int;
	delete pint;
	Test* ptr = new Test[10];
	delete[] ptr;
	return 0;
}
#endif


