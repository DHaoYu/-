#define _CRT_SECURE_NO_WARNNINGS 1

#include"SequListNew.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

void CheckSqList(PSqList ps)//�����
{
	if (ps->Length == ps->Size)
	{
		TypeData *ptr;
		ptr = (TypeData *)malloc(sizeof(TypeData)* 2 * ps->Size);
		memcpy(ptr, ps->elem, sizeof(TypeData)*ps->Size);//void *memcpy( void *dest, const void *src, size_t count );
		free(ps->elem);
		ps->elem = ptr;
		ps->Size = ps->Size * 2;
	}
}

void InitSqList(PSqList ps)//˳����ʼ��
{
	assert(ps);
	ps->Size = 3;
	ps->Length = 0;
	ps->elem = (TypeData*)malloc(sizeof(TypeData)*ps->Size);                     
}

void SqListPushFront(PSqList ps,TypeData data)//˳���ͷ��
{
	assert(ps->elem);
	CheckSqList(ps);//�ж�˳����Ƿ�Ϊ��
	for (int i = ps->Length; i > 0; i--)
	{
		ps->elem[i] = ps->elem[i - 1];
	}
	ps->elem[0] = data;
	ps->Length++;
}

void SqListPushBack(PSqList ps,TypeData data)//˳���β��
{
	assert(ps->elem);
	CheckSqList(ps);
	ps->elem[ps->Length] = data;
	ps->Length++;
}

void SqListPopFront(PSqList ps)//˳���ͷɾ
{
	for (int i = 0; i < ps->Length - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}
	ps->Length--;
}

void SqListPopBack(PSqList ps)//˳���βɾ
{
	ps->Length--;
}

void SqListDelete(PSqList ps, int pos)//����λ��ɾ��
{
	assert(ps->elem);
	if (pos >= ps->Length)
		return;
	for (int i = pos; i < ps->Length; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}
	ps->Length--;
}

void SqListInsert(PSqList ps, int pos, TypeData data)//����λ�ò��루֮ǰ�壩
{
	assert(ps->elem);
	if (pos >= ps->Length)
		return;
	CheckSqList(ps);
	for (int i = ps->Length - 1; i >= pos; i--)
	{
		ps->elem[i + 1] = ps->elem[i];
	}
	ps->elem[pos] = data;
	ps->Length++;
}
void SqListPrint(PSqList ps)
{
	for (int i = 0; i < ps->Length; i++)
	{
		printf("%d ", ps->elem[i]);
	}
	printf("\n");
}