#include<stdio.h>
#include"SequList.h"
#include<assert.h>
#include<malloc.h>

void SeqListInit(PSeqList ps)//³õÊ¼»¯Ë³Ðò±í
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

void SeqListDestroy(PSeqList ps)//Ïú»ÙË³Ðò±í
{
	free(ps->_array);
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//Ë³Ðò±íÎ²²å
{	
	//CheckSeqList();//FULL
	ps->_array[ps->_size] = data;
	ps->_size++;
}

void SeqListPopBack(PSeqList ps)//Ë³Ðò±íÎ²É¾
{
	assert(ps->_array);
	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)//Ë³Ðò±íÍ·²å
{
	assert(ps->_array);
	int i = 0;
	for (i = ps->_size ; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(PSeqList ps)//Ë³Ðò±íÍ·É¾
{
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType datda)
{

}