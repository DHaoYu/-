#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#if 0
//设置两个标记点标记奇数位和偶数位，然后与数组的最后一位数进行比较交换，
//这样可以使每一次最后一位都是新，并且odd与even每次都向后进行了移动，直到移动到
//最后一个位置，跳出循环，交换完成
class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int odd = 1;
		int even = 0;
		while (int i = len-1)
		{
			if (arr[i] % 2 == 0)
			{
				swap(arr[i], arr[even]);
				even += 2;
				i += 1;
			}
			else
			{
				swap(arr[i], arr[odd]);
				odd += 2;
				i += 1;
			}
			if (odd == i || even == i)
				break;
		}
	}
};

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5 };
	Solution s;
	s.oddInOddEvenInEven(arr, 5);
	for (auto e : arr)
		cout << e << " ";
	return 0;
}
#endif


#if 0
//嵌套循环，时间复杂度过大！
void MonkeyDP(int n)
{
	int x = 1;
	while (1)
	{
		int m = n;
		int temp = x;
		while (m--)
		{
			if (temp % 5 != 1)
				break;
			else
			{
				temp = temp / 5;
				temp *= 4;
			}
			if (m == 0)
			{
				cout << x << " " << n + temp << endl;
				return;
			}

		}
		x += 5;
	}
	return;
}


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		MonkeyDP(n);
	}

	return 0;
}
#endif
