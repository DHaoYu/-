#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
//红与黑
// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

void BlackCount(vector<vector<char>>& v, int x, int y, int m, int n, int& count)
{
	if (x<0 || y<0 || x >= m || y >= n || v[x][y] == '1'||v[x][y]=='#')
		return;
	count++;
	v[x][y] = '1';
	BlackCount(v, x - 1, y, m, n, count);
	BlackCount(v, x, y - 1, m, n, count);
	BlackCount(v, x + 1, y, m, n, count);
	BlackCount(v, x, y + 1, m, n, count);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		getchar();
		int x, y;
		int count = 0;
		vector<vector<char>> v(m, vector<char>(n, 0));//使用vector生成一个二维数组
		for (size_t i = 0; i<m; i++)
		{
			for (size_t j = 0; j<n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		BlackCount(v, x, y, m, n, count);
		cout << count << endl;
	}
	return 0;
}
#endif

