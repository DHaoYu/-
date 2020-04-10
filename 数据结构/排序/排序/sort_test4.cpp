#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Sort
{
public:
	Sort(vector<T> vec)
		:v(vec)
	{
	}

	void InsertSort()
	{
		for (int i = 1; i < (int)v.size(); ++i)
		{
			for (int j = i; j > 0; --j)
			{
				if (v[j] < v[j - 1])
					swap(v[j], v[j - 1]);
			}
		}
	}

	void BubbleSort()
	{
		for (int i = 0; i < (int)v.size(); ++i)
		{
			for (int j = 0; j < (int)v.size() -1-i; ++j)
			{
				if (v[j] > v[j + 1])
					swap(v[j], v[j + 1]);
			}
		}
	}

	void SelectSort()
	{
		for (int i = 0; i < (int)v.size(); ++i)
		{
			int pos = i;
			for (int j = i+1; j < (int)v.size(); ++j)
			{	
				if (v[pos] > v[j])
					pos = j;
			}
			swap(v[i], v[pos]);
		}
	}

	void ShellSort()
	{
		int gap = v.size() / 3;
		while (gap >= 1)
		{
			for (int i = 0; i < gap; ++i)
				_ShellSort(i, gap);
			gap /= 2;
		}
	}

	void HeapSort()
	{
		_CreatHeap();
		_HeapSort();
	}

	void QuickSort()
	{
		_QuickSort(0, v.size()-1);
	}

	void PirntSort()
	{
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
private:
	void _QuickSort(int begin, int end)
	{
		if (begin >= end)
			return;
		int start = begin, finish = end;
		T base = v[begin];
		while (begin < end)
		{
			while (v[end] > base && end > begin)
				end--;
			swap(v[end], base);
			while (v[begin] < base && begin < end)
				begin++;
			swap(v[begin], base);
		}
		v[begin] = base;

		_QuickSort(start, begin-1);
		_QuickSort(begin + 1, finish);
	}

	void _CreatHeap()
	{
		int p = v.size() / 2 - 1;
		for (; p >= 0; --p)
		{
			int parent = p;
			int lchild = parent * 2 + 1;
			int rchild = lchild + 1;
			while (lchild < (int)v.size())
			{
				if (rchild < (int)v.size() && v[rchild] > v[lchild])
					swap(v[rchild], v[lchild]);
				if (v[parent] < v[lchild])
					swap(v[parent], v[lchild]);
				parent = lchild;
				lchild = parent * 2 + 1;
				rchild = lchild + 1;
			}
		}
	}

	void _AdjustHeap(int len)
	{
		int parent = 0;
		int lchild = parent * 2 + 1;
		int rchild = lchild + 1;
		while (lchild < len)
		{
			if (rchild < len && v[rchild] > v[lchild])
				swap(v[rchild], v[lchild]);
			if (v[parent] < v[lchild])
				swap(v[parent], v[lchild]);
			parent = lchild;
			lchild = parent * 2 + 1;
			rchild = lchild + 1;
		}
	}

	void _HeapSort()
	{
		int len = (int)v.size();
		while (--len)
		{
			swap(v[0], v[len]);
			_AdjustHeap(len);
		}
	}

	void _ShellSort(int k, int gap)
	{
		for (int i = k; i < (int)v.size() - gap; i += gap)
		{
			for (int j = gap + i; j >= gap; j -= gap)
			{
				if (v[j] < v[j - gap])
					swap(v[j], v[j - gap]);
			}
		}
	}
private:
	vector<T> v;
};


int main()
{
	vector<int> vec = { 1, 5, 6, 2, 4, 7, 9, 8, 0, 3 };
	Sort<int> s(vec);
	//s.InsertSort();
	//s.BubbleSort();
	//s.SelectSort();
	//s.ShellSort();
	//s.HeapSort();
	s.QuickSort();
	s.PirntSort();
	return 0;
}