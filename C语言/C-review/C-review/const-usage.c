#define _CRT_SECURE_NO_WARNNINGS
#include<malloc.h>
#include<stdio.h>

#if 0
/*
����const���������ָ��������Ľ���
1.���ڱ���constֻ���ƿ��������ݲ����޸�
2.����ָ�������������*Ϊ�仯��
2.1��*��ǰ��const �����䲻�ɽ�ָ���ڱ����ֵ�����޸�
2.2��*�ź��const �����䲻�ɽ�ָ����ָ������ݽ����޸�
*/
int main()
{
	int a1 = 1;
	int b1 = 2;
	const int a2 = a1;//��aa2��ͬ��const����ķ�ָ��������������͵�ǰ��
	int const aa2 = a1;//����Ч����ͬ�������ƶ�������޸�

	int *a3 = &a1;
	const int* a4 = &a1;//cosnt data,non-const pointer
	int const* a5 = &a1;//const data.non-const pointer
	int* const a6 = &a1;//non-const data,const pointer

	//int* a7 const = &a1;//���ʽ�Ƿ�
	const int* const a8 = &a1;//non-const data,non-const pointer
	int const* const a9 = &a1;//non-const data, non-const pointer
	//a2 = 10;
	//aa2 = 10;false
	//a4 = &b1;//true
	//(*a4) = 10;false
	//a5 = &b1;//true
	//(*a5) = 10;//false
	//a6 = &b1;//false
	//(*a6) = 10;//true
	//a8 = &b1;//false
	//(*a8) = 10;//false
	//a9 = &b1;//false
	//(*a9) = 10;//false
	return 0;
}
#endif

#if 0
typedef struct SList
{
	int data;
	struct SList* _pNext;
}SList;

void InitSList(SList* s)
{
	s = (SList*)malloc(sizeof(SList));
	s->data = 0;
}

int main()
{
	const SList S;
	InitSList(&S);
	return 0;
}
#endif

#if 0
int main()
{
	int const a = 10;
	int* const pa = &a;
	printf("%d ", a);
	*pa = 20;
	printf("%d ", a);
	return 0;
}

#endif

#if 0
#define S(x) x*x //�ڱ���׶λ�Ѵ��������ݸ�Ϊ--> û������-- 1+2*1+2
#define S1(x) (x)*(x)
int main()     
{
	printf("%d \n", S(1 + 2));
	printf("%d \n", S1(1 + 2));

	return 0;
}
#endif

