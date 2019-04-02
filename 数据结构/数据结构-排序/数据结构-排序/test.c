#define _CRT_SECURE_NO_WARNNINGS 1

#include"Sort.h"

int main()
{
	int array[] = { 4, 3, 6, 8, 2, 9, 0, 1, 5, 7 };
	int size = sizeof(array) / sizeof(array[0]) - 1;

	QuickSort(array, 0, size);
	InsertSort(array, size);
	MergeSort(array,size);
	ShellSort(array, size);
	HeapSort(array, size+1);
	BubbleSort(array, size);
	SelectSort(array, size);
	PrintSort(array, size);
	return 0;
}

