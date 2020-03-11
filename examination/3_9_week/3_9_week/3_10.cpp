// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int RedBlack(vector<vector<char>> &v, int x, int y, int &num)
{
	if (x < 0 || y < 0 || x > v.size() || y > v[x].size())
		return num;
	if (v[x][y] == '#')
		return num;
	if (v[x][y] == '.')
		return 1 + num;
	//num += RedBlack(v, x, y - 1, num);
	//num += RedBlack(v, x, y + 1, num);
	//num += RedBlack(v, x - 1, y, num);
	//num += RedBlack(v, x + 1, y, num);

	return num + RedBlack(v, x, y - 1, num) + RedBlack(v, x, y + 1, num)
		+ RedBlack(v, x - 1, y, num) + RedBlack(v, x + 1, y, num);
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
		cout << RedBlack(v, x, y, num) << endl;
	}
	return 0;
}
