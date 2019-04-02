#define _CRT_SECURE_NO_WARNNINGS 1
#include"Queue.h"
#include<malloc.h>
#include<assert.h>
#include <stdio.h>


void QueueInit(PQueue q)//队列初始化
{
	assert(q);
	q->_capacity = 3;
	q->_size = 0;
	q->array = (QTypeData *)malloc(sizeof(QTypeData)*q->_capacity);
}


void CheckIsFullQueue(PQueue q)//判断队列是否为满--->扩容
{

	assert(q);
	QTypeData* arr = (QTypeData*)malloc(sizeof(QTypeData) * 2 * q->_capacity);
	
	if (q->_size != q->_capacity)
		return;

		for (int i = 0; i < q->_size; i++)
		{
			arr[i] = q->array[i];
		}
		q->array = arr;
		q->_capacity *= 2;
}

void PushQueue(PQueue q, QTypeData data)//入队列
{
	assert(q);

	CheckIsFullQueue(q);

	q->array[q->_size] = data;
	q->_size++;
}

void PopQueue(PQueue q)//出队列
{
	assert(q);

	for (int i = 1; i < q->_size; i++)
	{
		q->array[i - 1] = q->array[i];
	}
	q->_size--;
}

QTypeData GetFirstQueue(PQueue q)//获取队首元素
{
	return q->array[0];
}

QTypeData GetLastQueue(PQueue q)//获取队尾元素
{
	return q->array[q->_size];
}

int GetQueueSize(PQueue q)//获取队中元素个数
{
	return q->_size;
}

void DestoryQueue(PQueue q)//队列的销毁
{
	assert(q);
	free(q->array);
	q->_capacity = 0;
	q->_size = 0;
}