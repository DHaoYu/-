#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>
using namespace std;

#if 0
//对数组进行排序--直接插入排序
int* SortLevel(int N,int** arr)
{
    int i=0;
    int j=0;
    for(i=1;i<N;i++)
    {
    	int i=j;
        while(j)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
#endif

#if 0
//参赛选手：每个组3人，分为n组，总人数为N = 3n，每组中间水平的人代表该组
//平均水平，求平均水平最高应该怎么分配，例如：1 2 5 5 5 8
//可分为 125 558 平均为7  但是，分为155 258 平均则为10 选取10进行输出
int Max_avgLevel(int N, int arr[])
{
	// SortLevel(N,&arr);
	int j = 0;
	int n = N / 3;

	for (int i = 1; i<N; i++)
	{
		j = i;
		while (j && (arr[j]<arr[j - 1]))
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
	for (int j = 0; j<n; j++)
	{
		for (int i = 2 * n - 1; i>n; i--)
		{
			if (arr[i] < arr[i + n - 1])
				swap(arr[i], arr[i - 1 + n]);

			if (arr[i]>arr[i + n])
				swap(arr[i], arr[i + n]);
		}
	}

	int sum = 0;

	for (int i = n; i<2 * n; i++)
	{
		sum += arr[i];

	}
	return sum;
}


void swap(int& left, int& right)
{
	int temp = 0;
	temp = left;
	left = right;
	right = temp;
}

int main()
{
	int n = 0;
	cin >> n;
	int N = 3 * n;
	if (n = 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int* array = new int[N];
	int i = 0;

	while (i<N)
	{
		cin >> array[i];
		i++;
	}

	cout << Max_avgLevel(N, array) << endl;

	return 0;
}
#endif

#if 0
//输入两个字符串，从第一字符串中删除第二个字符串中的所有字符
//例子：they are student  ||  aeiou  --> thy r stdnts

#include<string>

string& Del_char(string& s1, string& s2)
{
	size_t i = 0;
	while (i < s2.size())
	{
		for (size_t j = 0; j < s1.size(); j++)
		{
			if (s1[j] == s2[i])
				s1.erase(s1.begin()+j);
		}
		i++;
	}
	return s1;
}

int main()
{
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);

	s1 = Del_char(s1, s2);
	for (size_t i = 0; i < s1.size(); i++)
		cout << s1[i];
	cout << endl;

	return 0;
}
#endif
