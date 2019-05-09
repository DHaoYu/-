#include"Heap.h"
#include<malloc.h>
#include<assert.h>
#include<string.h>


void CreatHeap(Heap *hp,int length)//������
{
	assert(hp->array);
	hp->capacity = 10;
	hp->size = 0;
	hp->array = (HTypeDate*)malloc(sizeof(HTypeDate)*hp->capacity);
	HTypeDate arr[] = { 9, 4, 1, 6, 5, 3, 1, 3, 2, 10, 7};
	memcpy(hp->array, arr, sizeof(HTypeDate)* length);
	hp->size = length;
	hp->array = arr;
	HeapAdjustDown(hp);
 }


void HeapAdjustDown(Heap *hp)
{
	int parent = (hp->size - 2) / 2;
	int child;
	for (int i = (hp->size - 2) / 2; i >= 0; --i)
	{
		parent = i;
		child = parent * 2 + 1;
		while (child <= hp->size - 1)
		{
			if (hp->array[child] > hp->array[child + 1] && child+1<=hp->size-1)
				child++;
			if (hp->array[parent] > hp->array[child])
				swap(hp, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void swap(Heap *hp, int parent, int child)//����
{
	HTypeDate temp;
	temp = hp->array[parent];
	hp->array[parent] = hp->array[child];
	hp->array[child] = temp;
}

Heap* CheckIsFuLLHeap(Heap *hp)
{
	assert(hp->array);
	if (hp->size == hp->capacity)
	{
		HTypeDate* arr = (HTypeDate *)malloc(sizeof(HTypeDate)*hp->capacity * 2);
		memcpy(arr, hp->array, sizeof(HTypeDate)*hp->capacity);
		free(hp->array);
		hp->array = arr;
		hp->capacity = hp->capacity * 2;
	}
	return hp;
}

void InsertHeap(Heap *hp,HTypeDate data)//�Ѳ���
{
	CheckIsFuLLHeap(hp);
	hp->array[hp->size] = data;
	hp->size++;
	HeapAdjustDown(hp);
}

void DeledteTopHeap(Heap *hp)//ͷ���ɾ��
{
	hp->array[0] = hp->array[hp->size - 1];
	hp->size--;
	HeapAdjustDown(hp);
}
void DestoryHeap(Heap* hp)//���ٶ�
{
	free(hp->array);
	hp->capacity = 0;
	hp->size = 0;
}

int IsemptyHeap(Heap *hp)//�п�
{
	if (hp->size == 0)
		return 0;
	else return 1;
}

HTypeDate TopHeap(Heap *hp)//���ضѶ�
{
	return hp->array[0];
}

int SizeHeap(Heap *hp)//���ض���Ԫ�ظ���
{
	return hp->size;
}