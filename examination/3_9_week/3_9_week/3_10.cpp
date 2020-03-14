// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;


#if 0
//ºìÓëºÚ   dfs
void RedBlack(vector<vector<char>> &v, int x, int y, int& num)
{
	if (x < 0 || y < 0 || x >= v.size() || y >= v[0].size()|| v[x][y] == '#')
		return ;

	++num;
	v[x][y] = '#';
	RedBlack(v, x, y - 1, num);
	RedBlack(v, x, y + 1, num);
	RedBlack(v, x - 1, y, num);
	RedBlack(v, x + 1, y, num);
}

int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		vector<vector<char>> v(m, vector<char>(n, 0));

		getchar();
		char k;
		int x, y;
		for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
		{
			cin >> k;
			if (k == '@')
			{
				x = i;
				y = j;
			}
			v[i][j] = k;
		}
		int num = 0;
		RedBlack(v, x, y, num);
		cout << num << endl;
	}
	return 0;
}
#endif

#if 0
//Ä¢¹½Õó
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m, n, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			v[x][y] = 1;
		}
		vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
		dp[1][1] = 1.0;
		for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
		{
			if (!(i == 1 && j == 1))
				dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);
			if (v[i][j] == 1)
				dp[i][j] = 0;
		}
		printf("%.2f\n", dp[n][m]);
	}
}
#endif