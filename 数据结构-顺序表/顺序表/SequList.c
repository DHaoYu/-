#define _CRT_SECURE_NO_WARNNINGS 1

#include<stdio.h>
#include"SequList.h"
#include<assert.h>
#include<malloc.h>
#include <memory.h>
#include<string.h>


void SeqListInit(PSeqList ps)//初始化顺序表
{
	assert(ps);
	ps->_array = (DataType*)malloc(sizeof(DataType)* 3);
	if (NULL == ps->_array)
	{
		assert(0);
	}
	ps->_capacity = 3;
	ps->_size = 0;
}

void CheckSeeqList(PSeqList ps)
{
	if (ps->_size == ps->_capacity)
	{
		DataType* ptr;
		ptr = (DataType* )malloc(sizeof(DataType)* 2 * ps->_capacity);
		memcpy(ptr, ps->_array,sizeof(DataType)*ps->_capacity);  //void *memcpy(void *dest, const void *src, size_t count);
		ps->_array =NULL;
		free(ps->_array);
		ps->_array = ptr;
		ps->_capacity = 2 * ps->_capacity;
	}
}


void SeqListDestroy(PSeqList ps)//销毁顺序表
{
	free(ps->_array);
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//顺序表尾插
{
	assert(ps);
	CheckSeeqList(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

void SeqListPopBack(PSeqList ps)//顺序表尾删
{
	assert(ps->_array);
	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)//顺序表头插
{
	CheckSeeqList(ps);
	assert(ps->_array);
	int i = 0;
	for (i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(PSeqList ps)//顺序表头删
{
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//顺序表任意位置插入
{
	for (int i = ps->_size; i>pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeqList ps, int pos)//顺序表任意位置删除
{
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

int SeqListFind(PSeqList ps, DataType data)
{
	for (int i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			printf("找到该元素！\n");
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void SeqListRemove(PSeqList ps, DataType data)
{
	for (int i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			for (int j = i; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			return;
		}
		else
		{
			printf("未找到data\n");
			return;
		}
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data)//删除所有data数据
{
	int i = 0;
	while(i <= ps->_size)
	{
		for (i = 0; i < ps->_size; i++)
		{
			if (data == ps->_array[i])
			{
				for (int j = i; j < ps->_size; j++)
				{
					ps->_array[j] = ps->_array[j + 1];
				}
				ps->_size--;
			}
			else
			{
				printf("已删除所有%d\n",data);
				return;
			}
		}
	}
}

int SeqListSize(PSeqList ps)//获取顺序表中有效元素个数
{
	printf("有效元素有%d个\n",ps->_size);
	return ps->_size;
}

int SeqListCapacity(PSeqList ps)
{
	printf("容量为%d\n", ps->_capacity );
	return ps->_capacity;
}

int SeqListEmpty(PSeqList ps)
{
	if (NULL == ps->_array)
	{
		printf("为空");
		return 0;
	}
	else
		return 1;
}

DataType SeqListFront(PSeqList ps)
{
	
	return printf("%d\n",ps->_array[0]);
}

DataType SeqListBack(PSeqList ps)
{
	return printf("%d\n", ps->_array[ps->_size - 1]);
}


////////////////////////////////////////////////
void PrintSeqList(PSeqList ps)
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}