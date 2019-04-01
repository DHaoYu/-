#define _CRT_SECURE_NO_WARNNINGS 1

#include"Sort.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

void Swap(int *left, int *right)
{
	int temp = 0;

	temp = *left;
	*left = *right;
	*right = temp;
}
#if 0
void QuickSort(int *array, int left, int right)
{

	if (left >= right)
		return;
	int temp = 0;
	int key = array[left];

	while (left < right)
	{
		if (array[right]<=key)
		{
			while (left<right)
			{
				if (array[left]>key)
				{
					temp = array[left];
					array[left] = array[right];
					array[right] = temp;
					break;
				}
				left++;
			}
		}
		right--;
	}
	array[0] = array[left];
	array[left] = key;

	QuickSort(array, 0, left);
	QuickSort(array, right + 1, (sizeof(array) / sizeof(array[0]) -1));

}
#endif

void InsertSort(int *array, int size)//直接插入排序
{
	assert(array);
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		j = i;
		while (array[j] < array[j - 1] && j - 1 >= 0)
		{
			Swap(&array[j], &array[j - 1]);
			j--;
		}
	}

}

void ShellSort(int *array, int size)//希尔排序
{
	int gap = (size / 3) + 1;
	int i = 0;
	int j = 0;
	while (gap > 0)
	{
		for (i = gap; i <= size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				Swap(&array[j], &array[j - gap]);
			}
		}
		gap--;
	}

}


void QuickSort(int *array, int left, int right)//快排
{
	assert(array);
	int i = left;
	int j = right;
	int temp = 0;
	int key = array[left];

	if (left >= right)
		return;
	while (i < j)
	{
		while (array[j] >= key && i < j)
			j--;

		while (array[i] <= key && i < j)//再找右边
			i++;

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	array[left] = array[i];
	array[i] = key;

	QuickSort(array, left, i);
	QuickSort(array, j+1, right);
}

#if 0
void HeapAdjust(int *arr, int start, int end)//O(logn),O(1)
{
	int tmp = arr[start];
	int i;
	for (i = 2 * start + 1; i <= end; i = 2 * i + 1)
	{
		if (i + 1 <= end && arr[i]<arr[i + 1])//i是左右孩子较大值的下标
			i++;
		if (tmp < arr[i])//arr[i]需要上移
		{
			arr[(i - 1) / 2] = arr[i];
		}
		else  //找到位置
		{
			break;
		}
	}
	arr[(i - 1) / 2] = tmp;
}

void HeapSort(int *arr, int len)//O(nlogn),O(1),不稳定
{
	//第一次建大根堆
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		HeapAdjust(arr, i, len - 1);
	}

	int tmp;
	for (int i = 0; i<len - 1; i++)
	{
		tmp = arr[0];
		arr[0] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
		HeapAdjust(arr, 0, len - 1 - i - 1);
	}
}
#endif

#if 0
//归并排序
//一趟归并
static void Merge(int *arr, int len, int gap)
{
	int low1 = 0;//第一个归并的的起始下标
	int high1 = gap - 1;//第一个归并段的结尾下标
	int low2 = high1 + 1;//第二个归并段的起始下标
	int high2 = low2 + gap - 1<len - 1 ? low2 + gap - 1 : len - 1;//第二个归并段的结尾下标	
	int *brr = (int *)malloc(sizeof(int)*len);//存放归并好的数据
	int i = 0;//brr下标

	//有两个归并段
	while (low2 <= high2)
	{
		//两个归并段都还有数据
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] <= arr[low2])
			{
				brr[i++] = arr[low1++];
			}
			else
			{
				brr[i++] = arr[low2++];
			}
		}

		//一个段数据归并完成，另一个还有数据
		while (low1 <= high1)
		{
			brr[i++] = arr[low1++];
		}

		while (low2 <= high2)
		{
			brr[i++] = arr[low2++];
		}

		low1 = high2 + 1;
		high1 = low1 + gap - 1;
		low2 = high1 + 1;
		high2 = low2 + gap - 1<len - 1 ? low2 + gap - 1 : len - 1;
	}

	//不足两个归并段
	while (low1 < len)
	{
		brr[i++] = arr[low1++];
	}

	for (i = 0; i<len; i++)
	{
		arr[i] = brr[i];
	}
	free(brr);
}

void MergeSort(int *arr, int len)//O(nlogn),O(n),稳定
{
	for (int i = 1; i<len; i *= 2)//归并段的长度
	{
		Merge(arr, len, i);
	}
}
#endif

void BubbleSort(int* array,int size)
{
	int first = 0;
	int second = 0;

	for (first = 0; first <= size; first++)
	{
		for (second = 0; second <=first; second++)
		{
			if (array[first] < array[second])
				Swap(&array[first], &array[second]);
		}
	}
}

void SelectSort(int* array, int size)//选择排序
{
	int min = 0;
	int max = 0;
	int begin = 0;
	int end = size;
	int i = 0;

	while (begin<end)
	{
		
		for (; i <= size; i++)
		{
			if (array[min] > array[i])
				min = i;
			if (array[max] < array[i])
				max = i;
		}
		Swap(&array[begin++], &array[min]);
		Swap(&array[end--], &array[max]);
	
		i = begin;
		size = end;
	}

}

void Merge(int *array, int first, int mid, int last,int *temp)
{
	int i = first;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= last)
	{
		if (array[i] > array[j])
			temp[k++] = array[j++];
		else
			temp[k++] = array[i++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= last)
		temp[k++] = array[j++];


	for (i = 0; i < k; i++)
		array[first+i] = temp[i];
}

void Merge_sort(int *array,int first,int last,int *temp)
{
	int mid = (last + first) / 2;
	
	if (first < last)
	{
		Merge_sort(array, first, mid, temp);
		Merge_sort(array, mid + 1, last, temp);
		Merge(array, first, mid, last, temp);
	}
	else
		return;

}

void MergeSort(int* array, int size)//归并排序
{
	int* temp = (int *)malloc(sizeof(int)*(size + 1));

	if (array == NULL && size <= 1)
		return;

	Merge_sort(array, 0, size, temp);
}

void PrintSort(int *array,int size)
{
	for (int i = 0; i <= size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

