#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>
using namespace std;

#if 0
//�������������--ֱ�Ӳ�������
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
//����ѡ�֣�ÿ����3�ˣ���Ϊn�飬������ΪN = 3n��ÿ���м�ˮƽ���˴������
//ƽ��ˮƽ����ƽ��ˮƽ���Ӧ����ô���䣬���磺1 2 5 5 5 8
//�ɷ�Ϊ 125 558 ƽ��Ϊ7  ���ǣ���Ϊ155 258 ƽ����Ϊ10 ѡȡ10�������
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
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ����е������ַ�
//���ӣ�they are student  ||  aeiou  --> thy r stdnts

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
