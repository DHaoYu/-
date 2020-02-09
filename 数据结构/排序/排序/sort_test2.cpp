#define _CRT_SECURE_NO_WARNNINGS 1
#include<vector>
#include<iostream>
using namespace std;

void InsertSort(vector<int>& v)
{
	for (int i = 0; i < v.size()-1; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

void BubbleSort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size()-1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

void SelectSort(vector<int>& v)
{
	int min_pos = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			if (v[j] < v[min_pos])
				min_pos = j;
		}
		swap(v[i], v[min_pos]);
		min_pos = i + 1;
	}
}

void GroupSort(vector<int>& v, int i, int gap)
{
	for (; i < v.size() - gap; i += gap)
	{
		for (int j = i; j >= 0; j -= gap)
		{
			if (v[j] > v[j + gap])
				swap(v[j], v[j + gap]);
		}
	}
}

void ShellSort(vector<int>& v)
{
	int gap = v.size();
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
			GroupSort(v, i, gap);
	}

}
void AdjustDown(vector<int>& v, int root, int len)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < len)
	{
		if (child + 1 < len && v[child] < v[child + 1])
			child++;
		if (v[parent] < v[child])
			swap(v[parent], v[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}

void CreateHeap(vector<int>& v)
{
	int parent = 0;
	int child = 2 * parent + 1;
	for (int i = v.size() / 2 - 1; i >= 0; i--)
	{
		AdjustDown(v, i, v.size());
	}
}

void HeapSort(vector<int>& v)
{
	CreateHeap(v);
	int len = v.size();
	while (len--)
	{
		swap(v[0], v[len]);
		AdjustDown(v, 0, len);
	}
}

void QuickSort(vector<int>& v, int low, int high)
{
	if (low == high)
		return;
	int start = low, end = high;
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
	QuickSort(v, start, low);
	QuickSort(v, low + 1, end);
}

void Merge(vector<int>& v, int L, int M, int R)
{
	int* left = (int*)malloc(sizeof(int)*(M - L));
	int* right = (int*)malloc(sizeof(int)*(R - M + 1));
	for (int i = 0; i < M - L; i++)
		left[i] = v[i + L];
	for (int i = 0; i < R - M + 1; i++)
		right[i] = v[i + M];
	int i = 0, j = 0, k = L;
	while (i < (M - L) && j < (R - M + 1))
	{
		while (i < (M - L) && left[i] < right[j])
			v[k++] = left[i++];
		while (j < (R - M + 1) && right[j] < left[i])
			v[k++] = right[j++];
	}
	while (i < M - L)
		v[k++] = left[i++];
	while (j < R - M + 1)
		v[k++] = right[j++];
}

void MergeSort(vector<int>& v, int L, int R)
{
	if (L == R)
		return;
	int M = (L + R) / 2;
	MergeSort(v, L, M);
	MergeSort(v, M + 1, R);
	Merge(v, L, M+1, R);
}

void BucketSort(vector<int>& v)
{
	vector<int> vc(10, 0);
	for (int i = 0; i < vc.size(); i++)
	{
		vc[v[i]]++;
	}
	for (int i = 0; i < vc.size(); i++)
	{
		for (int j = 1; j <= vc[i]; j++)
			cout << i << " ";
	}
	cout << endl;
}

void sortColors(int A[], int n) {
	int begin = 0, end = n - 1, cur = 0;
	while (cur <= end){
		if (A[cur] == 0){
			swap(A[begin], A[cur]);
			// 指向排序0末尾的下一个位置
			++begin;
			// 向前遍历
			++cur;
		}//if
		else if (A[cur] == 1){
			++cur;
		}//else
		else{
			swap(A[end], A[cur]);
			// 指向排序2开头的前一个位置
			--end;
		}//else
	}//for
}

class B
{
private:
	static int a;
};

int B::a = 10;

int main()
{
	vector<int> v = { 5, 4, 7, 9, 0, 1, 6, 8, 2, 3 };
	vector<int> v1 = { 2, 4, 5, 8, 1, 3, 7, 9 };
	int a[] = { 0, 2, 2, 0, 0, 1, 2, 2, 2 };
	sortColors(a, 9);
	//vector<int> * v2 = new vector<int>(10, 0);
	//InsertSort(v);
	//BubbleSort(v);
	//SelectSort(v);
	//ShellSort(v);
	//HeapSort(v);
	//QuickSort(v, 0, v.size()-1);
	//Merge(v1, 0, 4, 7);
	//MergeSort(v, 0, 9);
	//BucketSort(v);
	B b;
	cout << sizeof(B) << endl;
	cout << sizeof(b) << endl;

	//for (auto e : a)
	//	cout << e << " ";
	return 0;
}