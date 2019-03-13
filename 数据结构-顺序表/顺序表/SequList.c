#define _CRT_SECURE_NO_WARNNINGS 1

#include<stdio.h>
#include"SequList.h"
#include<assert.h>
#include<malloc.h>
#include <memory.h>
#include<string.h>


void SeqListInit(PSeqList ps)//��ʼ��˳���
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


void SeqListDestroy(PSeqList ps)//����˳���
{
	free(ps->_array);
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//˳���β��
{
	assert(ps);
	CheckSeeqList(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

void SeqListPopBack(PSeqList ps)//˳���βɾ
{
	assert(ps->_array);
	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)//˳���ͷ��
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

void SeqListPopFront(PSeqList ps)//˳���ͷɾ
{
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//˳�������λ�ò���
{
	for (int i = ps->_size; i>pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeqList ps, int pos)//˳�������λ��ɾ��
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
			printf("�ҵ���Ԫ�أ�\n");
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
			printf("δ�ҵ�data\n");
			return;
		}
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data)//ɾ������data����
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
				printf("��ɾ������%d\n",data);
				return;
			}
		}
	}
}

int SeqListSize(PSeqList ps)//��ȡ˳�������ЧԪ�ظ���
{
	printf("��ЧԪ����%d��\n",ps->_size);
	return ps->_size;
}

int SeqListCapacity(PSeqList ps)
{
	printf("����Ϊ%d\n", ps->_capacity );
	return ps->_capacity;
}

int SeqListEmpty(PSeqList ps)
{
	if (NULL == ps->_array)
	{
		printf("Ϊ��");
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