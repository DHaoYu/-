#define _CRT_SECURE_NO_WARNNINGS 

#include"Heap.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<memory.h>

void CheckHeapFull(pHeap h)
{
	if (h->capacity > h->size)
		return;
	else
	{
		Heap Newh;
		Newh.array = (HTypeData*)malloc(sizeof(h->array) * 2 * h->capacity);

		memcpy(Newh.array, h->array, sizeof(h->array)*h->capacity);
		free(h->array);
		h->array = Newh.array;
		h->capacity *= 2;

	}
}

void CreatHeap(pHeap h)//堆的创建
{
	assert(h);
	HTypeData arr[] = { 6, 3, 2, 1, 0, 4, 5 };
	h->array = (HTypeData*)malloc(sizeof(arr));
	h->capacity = sizeof(arr) / sizeof(arr[0]);
	h->size = h->capacity;
	memcpy(h->array, arr, sizeof(arr[0])*h->capacity);
	//int parent = (h->capacity - 1 - 1) / 2;//找最后一个非叶子结点，进行parent--
	//AdjustDownHeap(h, h->size);
	AdjustUpHeap(h, h->size);
}

void AdjustDownHeap(pHeap h,int size)//堆向下调整-->寻找第一个非叶子节点，找到parent结点，逐步向下进行调整
{
	int parent = (h->size - 1 - 1) / 2;
	if (h->size == 1 || h->array == NULL)
		return;
	int child = 0; 
	for (int i=parent; i >= 0; i--)//遍历每一个parent结点
	{
		parent = i;
		child = parent * 2 + 1;
		while (child < size)
		{
			if (h->array[child] > h->array[child + 1] && child+1 < size)
				child++;
			if (h->array[parent] > h->array[child])
				Swap(&h->array[parent], &h->array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void AdjustUpHeap(pHeap h, int size)//向上调整
{
	int child = size - 1;
	int parent = (child - 1) / 2;

	for (int i = size - 1; i > (size - 2) / 2; i--)
	{
		child = i;
		parent = (child - 1) / 2;
		while (h->array[child] < h->array[parent] &&  parent != child)
		{
			Swap(&h->array[child], &h->array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}
}

void Swap(HTypeData *parent, HTypeData *child)//交换parent与child中的值
{
	HTypeData temp = 0;
	temp = *parent;
	*parent = *child;
	*child = temp;
}

void InsertHeap(pHeap h, HTypeData data)//堆的插入
{
	assert(h);
	CheckHeapFull(h);
	h->array[h->size] = data;
	h->size++;
	AdjustDownHeap(h, h->size);
	
}

void EraseHeap(pHeap h)//堆顶元素清除
{
	HTypeData temp;
	temp = h->array[0];
	h->array[0] = h->array[h->size - 1];
	h->array[h->size - 1] = temp;
	h->size--;
	AdjustDownHeap(h, h->size);
}

void AdjustDownBigHeap(pHeap h, int size)//建立大堆
{
	int parent = (size - 1 - 1) / 2;
	int child = size - 1;

	for (int i = parent; i >= 0; i--)
	{
		parent = i;
		child = parent * 2 + 1;
		while (child <size)
		{
			if (h->array[child + 1] > h->array[child] && child + 1 < size)
				child++;
			if (h->array[child] > h->array[parent] && child < size)
				Swap(&h->array[parent], &h->array[child]);

			parent = child;
			child = parent * 2 + 1;
		}
	}
}

void HeapSrot(Heap* h)//堆排序
{
	HTypeData temp = 0;
	int size = h->size;

	while (size)
	{
		AdjustDownBigHeap(h, size);
		temp = h->array[0];
		h->array[0] = h->array[size-1];
		h->array[size-1] = temp;
		size--;
	}
	
}

void PrintHeap(pHeap h)//打印函数
{
	for (int i = 0; i < h->size; i++)
		printf("%d ", h->array[i]);
	printf("\n");
}

HTypeData TopHeap(pHeap h)//获取堆顶元素
{
	return h->array[0];
}

int SizeHeap(pHeap h)//获取堆的元素个数
{
	return h->size;
}

int EmptyHeap(pHeap h)//判断堆是否为空
{
	if (0 == h->size)
		return 1;
	else
		return -1;
}


void DsetoryHeap(pHeap h)
{
	free(h->array);
	h->capacity = 0;
	h->size = 0;
}