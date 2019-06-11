#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
using namespace std;

int main()
{
	int y, m, d;
	int sum;
	bool leap = false;
	cin >> y >> m >> d;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		leap = true;
	switch (m){
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4: sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:
		cout << -1 << endl;
		return 0;
	}
	if (d <= 0 || d >= 31)
	{
		cout << -1 << endl;
		return 0;
	}

	if (m == 2)
	{
		if (leap==false)
		if (d == 29)
			cout << -1 << endl;
		return 0;
	}

	sum += d;
	if (leap && m>2)
		sum++;
	cout << sum << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
#include <stdlib.h>
using namespace std;

int n;
int nums[1000];

int cmp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

// 思路：DFS生成全组合，同时注意剪枝、避免重复组合
int findall(int nums[], int index, long sum, long multi) {
	int count = 0;
	for (int i = index; i<n; i++) {
		sum += nums[i];
		multi *= nums[i];
		if (sum > multi)
			count += 1 + findall(nums, i + 1, sum, multi);
		else if (nums[i] == 1)
			count += findall(nums, i + 1, sum, multi);
		else
			break;
		sum -= nums[i];
		multi /= nums[i];
		// 跳过相等的元素，避免重复组合
		while (i<n - 1 && nums[i] == nums[i + 1])
			i++;
	}
	return count;
}

int main()
{
	while (cin >> n) {
		for (int i = 0; i<n; i++)
			cin >> nums[i];

		// 从小到大排序
		qsort(nums, n, sizeof(int), cmp);
		cout << findall(nums, 0, 0, 1) << endl;
	}
	//太难了，一点思路都没有！！！
	return 0;
}
#endif