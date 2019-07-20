#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


#if 0
//左右最大值差的最大值
int findMaxGap(vector<int> A, int n) {
	// write code here
	vector<int> B(A);
	size_t pos = 0;
	sort(B.begin(), B.end());
	for (size_t i = n - 1; i >= 0; i--)
	{
		if (A[i] == B[n - 1])
		{
			pos = i;
			break;
		}
	}

	return A[pos] - A[0]>A[pos] - A[n - 1] ? A[pos] - A[0] : A[pos] - A[n - 1];
}

int main()
{
	vector<int> A{ 2, 0, 5, 7, 3, 9, 8, 1, 6, 4 };
	cout << findMaxGap(A, 10) << endl;
	return 0;
}
#endif

#if 0
vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
	// write code here
	size_t i = 0, j = 0;
	vector<int> v;
	while (n>=2 && m>=2)
	{
		while (i<n)
		{
			v.push_back(mat[j][i]);
			i++;
		}
		i -= 1;
		j += 1;
		while (j<m)
		{
			v.push_back(mat[j][i]);
			j++;
		}
		j -= 1;
		while (i > m-j)
		{
			i--;
			v.push_back(mat[j][i]);
		}
		while (j > n-i)
		{
			j--;
			v.push_back(mat[j][i]);
		}
		i += 1;
		n -= 1;
		m -= 1;
	}
	return v;
}

int main()
{
	vector<vector<int>> v{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<int> v1 = clockwisePrint(v, 4, 4);
	return 0;
}
#endif