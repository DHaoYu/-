#include<iostream>

using namespace std;
#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		int R1, C1, L1;
		int R2, C2, L2;
		int max = 0;
	}
}

#endif

#if 0
#include <iostream>
#include <vector>
#include <stack>

void Core(const std::vector<int>& arr, std::vector<int>& cur, std::stack<int>& sta, 
			int index, std::vector<std::vector<int>>& res)
{
	if (sta.empty() && index == arr.size())
	{
		res.push_back(cur);
		return;
	}
	if (index < arr.size())
	{
		sta.push(arr[index]);
		Core(arr, cur, sta, index + 1, res);
		sta.pop();
	}
	if (!sta.empty())
	{
		int temp = sta.top();
		sta.pop();
		cur.push_back(temp);
		Core(arr, cur, sta, index, res);
		sta.push(temp);
		cur.pop_back();
	}
}
std::vector<std::vector<int>> Sol(std::vector<int> arr)
{
	std::vector<std::vector<int>> res;
	std::stack<int> sta;
	std::vector<int> cur;
	if (arr.size() < 1)
	{
		return res;
	}
	Core(arr, cur, sta, 0, res);
	return res;
}
int main()
{
	std::vector<std::vector<int>> res = Sol({ 1, 2, 3 });
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
#endif

#if 0
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		int pos, count = 0;
		while (1)
		{
			pos = str.find("001010");
			if (pos >= 0)
			{
				str.erase(pos + 3, 1);
				count++;
			}
			pos = str.find("0010");
			if (pos < 0)
				break;
			str.erase(pos + 2, 1);
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
#endif