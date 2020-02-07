#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
#include<iostream>
#include<vector>
using namespace std;

//直接插入排序
void InsertSort(vector<int> &v)
{
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j + 1] < v[j])
				swap(v[j+1], v[j]);
			else
				break;
		}
	}
}

//冒泡排序
void BubbleSort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j < v.size() - i; j++)
		{
			if (v[j - 1] > v[j])
				swap(v[j - 1], v[j]);
		}
	}
}

void GroupSort(vector<int> &v, int gap, int i)
{
	for (; i < v.size()-gap; i += gap)
	{
		for (int j = i; j >= 0; j -= gap)
		{
			if (v[j] > v[j + gap])
				swap(v[j + gap], v[j]);
		}
	}
}

//希尔排序
void ShellSort(vector<int>& v)
{
	int gap = v.size();
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
			GroupSort(v, gap, i);
	}
}

//选择排序
void SeclectSort(vector<int> &v)
{
	int min = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[j] < v[min])
				min = j;
		}
		swap(v[i], v[min]);
		min = i+1;
	}
}

void AdjustDown(vector<int>& v, int root, int len)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child <= len - 1)
	{
		if (child + 1 <= len - 1 && v[child] > v[child + 1])
			child++;
		if (v[parent] > v[child])
			swap(v[parent], v[child]);
		parent = child;
		child = 2 * parent + 1;
	}
}

void CreateHeap(vector<int> &v, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
		AdjustDown(v, i, len);
}

//堆排序
void HeapSort(vector<int> &v)
{
	//创建堆
	CreateHeap(v, v.size());
	//进行排序
	int len = v.size();
	while (len--)
	{
		swap(v[0], v[len]);
		AdjustDown(v, 0, len);
	}
}

//快速排序
void QuickSort(vector<int>& v, int low, int high)
{
	if (low >= high) //递归跳出条件
		return;
	int start = low;
	int end = high;
	int baseval = v[low];
	while (low < high)
	{
		while (low < high && v[high] > baseval)
			high--;
		v[low] = v[high];
		while (low < high && v[low] < baseval)
			low++;
		v[high] = v[low];
	}
	v[low] = baseval;
	QuickSort(v, start, low-1);
	QuickSort(v, low + 1, end);
}

void Merge(vector<int>& v, int L, int R, int M)
{
	int l_size = M - L;
	int r_size = R - M + 1;
	int *left = new int[l_size];
	int *right = new int[r_size];
	//int left[4];
	//int right[4];
	//对两个数组进行赋值 
	int i, j, k;
	for (i = L; i < M; i++)
		left[i - L] = v[i];
	for (j = M; j <= R; j++)
		right[j - M] = v[j];
	i = 0, j = 0, k = L;
	while (i < l_size && j < r_size)
	{
		if (left[i] < right[j])
		{
			v[k] = left[i];
			k++; i++;
		}
		else
		{
			v[k] = right[j];
			k++; j++;
		}
	}
	while (i < l_size)
	{
		v[k] = left[i];
		k++; i++;
	}
	while (j < r_size)
	{
		v[k] = right[j];
		k++; j++;
	}
}

//归并排序
void MergeSort(vector<int>& v, int L, int R)
{
	if (L == R)
		return;
	int M = (L + R) / 2;
	MergeSort(v, L, M);
	MergeSort(v, M+1, R);
	Merge(v, L, R, M+1);
}

int main()
{
	vector<int> v = { 7, 6, 3, 1, 9, 0, 4, 2, 5, 8 };
	vector<int> v1 = { 2, 4, 5, 8, 1, 3, 7, 9 };
	//Merge(v1, 0, 7, 4);
	//InsertSort(v);
	//BubbleSort(v);
	//ShellSort(v);
	//SeclectSort(v);
	//HeapSort(v);
	//QuickSort(v, 0, v.size() - 1);
	MergeSort(v, 0, 9);
	for (auto e : v)
		cout << e << " ";
	return 0;
}
#endif