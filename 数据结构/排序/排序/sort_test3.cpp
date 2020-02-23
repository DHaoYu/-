

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//��������
void InsertSort(vector<int> v, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
		}
	}
}
//ð������
void BubbleSort(vector<int> v, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j < len - i; j++)
		{
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
		}
	}
}

//ѡ������
void SelectSort(vector<int> v, int len)
{
	int minpos = 0;
	for (int i = 0; i < len; i++)
	{
		minpos = i;
		for (int j = i + 1; j < len; j++)
		{
			if (v[j] < v[minpos])
				minpos = j;
		}
		swap(v[minpos], v[i]);
	}
}

//ϣ������
void Shell(vector<int>& v, int gap, int i, int len)
{
	for (; i < len - gap; i += gap)
	{
		for (int j = i + gap; j > i; j -= gap)
		{
			if (v[j] < v[j - gap])
				swap(v[j], v[j - gap]);
		}
	}
}

void ShellSort(vector<int> v, int len)
{
	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++)
		{
			Shell(v, gap, i, len);
		}
	}
}
//������
void AdjustDown(vector<int>& v, int parent, int len)
{
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

void CreateHeap(vector<int>& v, int len)
{
	int parent = len - 1;
	for (; parent >= 0; parent--)
		AdjustDown(v, parent, len);

}

void HeapSort(vector<int> v, int len)
{
	CreateHeap(v, len);
	while (len--)
	{
		swap(v[0], v[len]);
		AdjustDown(v, 0, len);
	}
}

////��������
//void _QuickSort(vector<int>& v, int begin, int end)
//{
//	int finish = end;
//	int start = begin;
//	if (begin >= end) 
//		return;
//	int base = v[begin];
//	while (begin < end)
//	{
//		while (begin < end && v[end] > base)
//			end--;
//		v[begin] = v[end];
//		while (begin < end && v[begin] < base)
//			begin++;
//		v[end] = v[begin];
//	}
//	v[begin] = base;
//	_QuickSort(v, start, begin - 1);
//	_QuickSort(v, begin + 1, finish);
//}

//�������򣨴�С����
void _QuickSort(vector<int> arr, int left, int right)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	//��׼����λ
	arr[left] = arr[i];
	arr[i] = base;
	_QuickSort(arr, left, i - 1);//�ݹ����
	_QuickSort(arr, i + 1, right);//�ݹ��ұ�
}

void QuickSort(vector<int> v, int len)
{
	_QuickSort(v, 0, len - 1);
}

#include<stack>
int getPartition(vector<int> &nums, int low, int height)
{
	int keyVal = nums[low];
	while (low<height)
	{
		while (low < height&&nums[height] >= keyVal)
			height--;
		nums[low] = nums[height];
		while (low < height&&nums[low] <= keyVal)
			low++;
		nums[height] = nums[low];
	}
	nums[low] = keyVal;
	return low;
}

void quickSortNonRecursive(vector<int> &nums, int low, int height)
{
	stack<int> s;
	if (low<height)
	{
		int mid = getPartition(nums, low, height);
		if (mid - 1>low)
		{
			s.push(low);
			s.push(mid - 1);
		}
		if (mid + 1<height)
		{
			s.push(mid + 1);
			s.push(height);
		}

		while (!s.empty())
		{
			int qHeight = s.top();
			s.pop();
			int pLow = s.top();
			s.pop();
			int pqMid = getPartition(nums, pLow, qHeight);
			if (pqMid - 1 > pLow)
			{
				s.push(pLow);
				s.push(pqMid - 1);
			}
			if (pqMid + 1 < qHeight)
			{
				s.push(pqMid + 1);
				s.push(qHeight);
			}
		}

	}
}

////�鲢����
//void Merge(vector<int>& v, int L, int M, int R)
//{
//	int left_size = M - L + 1;
//	int right_size = R - M;
//	int* left = new int[left_size];
//	int* right = new int[right_size];
//	for (int i = 0; i < left_size; i++)
//		left[i] = v[i + L];
//	for (int i = 0; i < right_size; i++)
//		right[i] = v[i + M + 1];
//	int i = 0, j = 0, k = L;
//	while (i < left_size && j < right_size)
//	{
//		while (i < left_size && left[i] < right[j])
//			v[k++] = left[i++];
//		while (j < right_size && right[j] < left[i])
//			v[k++] = right[j++];
//	}
//	while(i < left_size)
//		v[k++] = left[i++];
//	while (j < right_size)
//		v[k++] = right[j++];
//}
void Merge(vector<int>& arr, int l, int mid, int r){
	int *help = new int[r - l + 1];//��������
	int i = 0;
	int lIndex = l;
	int rIndex = mid + 1;
	while (lIndex <= mid && rIndex <= r){
		help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++] : arr[rIndex++];
	}
	//��ߺ��ұ߿϶���һ�ߵ�ͷ�ˣ�������ͬʱ����Ϊÿ��ֻ�ƶ�һ��
	while (lIndex <= mid){
		help[i++] = arr[lIndex++];
	}
	while (rIndex <= r){
		help[i++] = arr[rIndex++];
	}
	//���ź���ĸ������鸳ֵ��ԭʼ���飬����Ҫ����ֵ
	for (i = 0; i < r - l + 1; i++){
		arr[l + i] = help[i];
	}
}

void _MergeSort(vector<int>& v, int L, int R)
{
	if (L == R)
		return;
	int M = (R + L) / 2;
	_MergeSort(v, L, M);
	_MergeSort(v, M + 1, R);
	Merge(v, L, M, R);
}

void MergeSort(vector<int> v, int len)
{
	int L = 0;
	int R = len - 1;
	_MergeSort(v, L, R);
}
//��������
#include<ctime>
void Func()
{
	vector<int> v;
	srand(time(nullptr));
	for (int i = 0; i < 1000; i++)
		v.push_back(rand() % 1000000);
	clock_t start, end;
	
	//start = clock();
	//quickSortNonRecursive(v, 0, 2999999);
	//end = clock();
	//cout << "3000000���ݣ�������������Ҫ��" << end - start << "����" << endl;
	
	start = clock();
	sort(v.begin(), v.end());
	end = clock();
	cout << "3000000���ݣ�algorithm�㷨��������Ҫ��" << end - start << "����" << endl;
}


int main()
{
	vector<int> v, v1;
	srand(time(nullptr));
	for (int i = 0; i < 100000000; i++)
		v.push_back(rand()%10000000000);
	clock_t start, end;
	//Func();
	//vector<int> v = { 5, 4, 7, 0, 9, 1, 3, 6, 2, 8 };
	/*
	start = clock();
	InsertSort(v, 100000000);
	end = clock();
	cout << "100000000���ݣ�����������Ҫ��" << end - start << "����" << endl;

	start = clock();
	BubbleSort(v, 100000000);
	sort(v.begin(), v.end());
	end = clock();
	cout << "100000000���ݣ�ð��������Ҫ��" << end - start << "����" << endl;
	
	start = clock();
	SelectSort(v, 100000000);
	end = clock();
	cout << "100000000���ݣ�ѡ��������Ҫ��" << end - start << "����" << endl;
	*/
	/*
	start = clock();
	ShellSort(v, 100000000);
	end = clock();
	cout << "100000000���ݣ�ϣ��������Ҫ��" << end - start << "����" << endl;
	*/
	/*
	start = clock();
	HeapSort(v, 100000000);
	end = clock();
	cout << "100000000���ݣ���������Ҫ��" << end - start << "����" << endl;
	*/

	//start = clock();
	//QuickSort(v, 100000000);
	//end = clock();
	//cout << "100000000���ݣ��������򣨵ݹ飩��Ҫ��" << "���ݹ��󣬵ݹ����Ч��̫��" << endl;
	//cout << "100000000���ݣ��������򣨵ݹ飩��Ҫ��" << end - start << "����" << endl;
	/*
	start = clock();
	quickSortNonRecursive(v, 0, 100000000 -1);
	end = clock();
	cout << "100000000���ݣ��������򣨷ǵݹ飩��Ҫ��" << end - start << "����" << endl;
	*/
	start = clock();
	MergeSort(v, 100000000);
	end = clock();
	cout << "100000���ݣ��鲢������Ҫ��" << end - start << "����" << endl;

	start = clock();
	sort(v.begin(), v.end());
	cout << "STL�е�sort������������Ҫ��" << end - start << "����" << endl;
	end = clock();
	return 0;
}