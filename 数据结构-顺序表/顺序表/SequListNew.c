#define _CRT_SECURE_NO_WARNNINGS 1

#include"SequListNew.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

void CheckSqList(PSqList ps)//检查满
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

void InitSqList(PSqList ps)//顺序表初始化
{
	assert(ps);
	ps->Size = 3;
	ps->Length = 0;
	ps->elem = (TypeData*)malloc(sizeof(TypeData)*ps->Size);                     
}

void SqListPushFront(PSqList ps,TypeData data)//顺序表头插
{
	assert(ps->elem);
	CheckSqList(ps);//判断顺序表是否为满
	for (int i = ps->Length; i > 0; i--)
	{
		ps->elem[i] = ps->elem[i - 1];
	}
	ps->elem[0] = data;
	ps->Length++;
}

void SqListPushBack(PSqList ps,TypeData data)//顺序表尾插
{
	assert(ps->elem);
	CheckSqList(ps);
	ps->elem[ps->Length] = data;
	ps->Length++;
}

void SqListPopFront(PSqList ps)//顺序表头删
{
	for (int i = 0; i < ps->Length - 1; i++)
	{
		ps->elem[i] = ps->elem[i + 1];
	}
	ps->Length--;
}

void SqListPopBack(PSqList ps)//顺序表尾删
{
	ps->Length--;
}

void SqListDelete(PSqList ps, int pos)//任意位置删除
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

void SqListInsert(PSqList ps, int pos, TypeData data)//任意位置插入（之前插）
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