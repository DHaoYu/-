#include<iostream>
using namespace std;

#if 0
//��������n��m����1��n����n���������ֵ�������֮�������еĵ�m�����֡�
//����n = 11��m = 4�����ֵ�����������Ϊ1, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9��
//��˵�4������Ϊ2��
long long getCountOfk(long long k, long long n)
{
	long long base = 1, count = 0;
	while (n >= (k + 1)*base - 1)
	{
		count += base;
		base *= 10;
	}
	if (n >= k*base)
		count += n - k*base + 1;
	return count;
}

long long getnumber(long long n, long long m)
{
	long long k = 1;
	while (m != 0)
	{
		long long count = getCountOfk(k, n);
		if (count >= m)
		{
			m--;
			if (m == 0)
				break;
			k *= 10;
		}
		else
		{
			k++;
			m = m - count;
		}
	}
	return k;

}

int main()
{
	long long n, m;
	while (cin >> n >> m)
		cout << getnumber(n, m) << endl;
	return 0;
}
#endif

// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

bool JudgeFiveLine(char v[][20])
{
	int dir[][2] = { { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
	int count = 1;
	for (int i = 0; i < 20; ++i)
	for (int j = 0; j < 20; ++j)
	{
		if (v[i][j] == '.')
			continue;
		for (int m = 0; m < 4; m++)
		{
			if (i + 4 < 20 && j + 4 < 20)
			{
				for (int k = 1; k < 5; ++k)
				{
					if (v[i][j] == v[i + k*dir[m][0]][j + k*dir[m][1]])
						++count;
				}
			}
			if (count == 5)
				return true;
			count = 1;
		}
	}
	return false;
}

int main()
{
	char k;
	while (cin >> k)
	{
		char v[20][20];
		char ch;
		for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
		{
			cin >> ch;
			v[i][j] = ch;
		}
		cout << (JudgeFiveLine(v) ? "Yes" : "No") << endl;
	}
}