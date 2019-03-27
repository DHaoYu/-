#define _CRT_SECURE_NO_WARNNINGS 

#include"Heap.h"

int main()
{
	Heap h;
	CreatHeap(&h);
	PrintHeap(&h);
	InsertHeap(&h, 9);
	PrintHeap(&h);
	InsertHeap(&h, 8);
	PrintHeap(&h);
	InsertHeap(&h, 1);
	PrintHeap(&h);
	EraseHeap(&h);
	PrintHeap(&h);
	HeapSrot(&h);
	PrintHeap(&h);
	return 0;
}