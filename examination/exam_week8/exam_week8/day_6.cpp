#define _CRT_SECURE_NO_WARNNINGS 1

// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

#if 0
//解读密码（提取数字）
void extNumber(string& str)
{
	string des;
	for (size_t i = 0; i<str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			des.push_back(str[i]);
	}
	cout << des << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		extNumber(str);
	}
	return 0;
}
#endif

//走迷宫 //写不出来！！
// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> dp;
void minStep(vector<string> v, int count, int x, int y)
{
	if (x == 9 && y == 8)
	{
		dp.push_back(count);
		return;
	}
	else
	{
		count++;
		v[x][y] = '1';
	}
	if (x + 1 <= 9 && v[x + 1][y] != '#' && v[x + 1][y] != '1')
		minStep(v, count, x + 1, y);
	if (y + 1 <= 9 && v[x][y + 1] != '#' && v[x][y + 1] != '1')
		minStep(v, count, x, y + 1);
	if (x - 1 >= 0 && v[x - 1][y] != '#' && v[x - 1][y] != '1')
		minStep(v, count, x - 1, y);
	if (y - 1 >= 0 && v[x][y - 1] != '#' && v[x][y - 1] != '1')
		minStep(v, count, x, y - 1);
}


int main()
{
	vector<string> maze(10);
	while (cin >> maze[0])
	{
		int count = 0, x = 0, y = 1;
		for (size_t i = 1; i<10; i++)
			cin >> maze[i];
		minStep(maze, count, x, y);
		cout << (*min_element(dp.begin(), dp.end())) << endl;
		dp.clear();
	}
	return 0;
}