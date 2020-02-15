#define _CRT_SECURE_NO_WARNINGS

#include<map>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<functional>
using namespace std;


#if 0
template<class T>
class Comp //比较器
{
public:
	bool operator()(const T& a, const T& b) const
	{
		return a > b;
	}
};

int main()
{
	map<int, string, Comp<int>> m;
	m.insert(make_pair(1, "apple")); //make_pair会进行类型推导
	m.insert(pair<int, string>(2, "banana"));
	m.insert(make_pair(3, "orange"));
	m.insert(make_pair(3, "orange1")); //
	for (auto& e : m)
	{
		cout << e.second << " " << e.first << " " << endl;
	}

	set<int, Comp<int>> s{ 1, 2, 3, 4 };
	for (auto& e : s)
		cout << e << " ";
	return 0;
}
#endif

#if 0
//递归二分查找
int BinarySearch1(vector<int>& v, int left, int right, int x)
{
	int mid = (left + right) / 2;
	if (left > right)
		return -1;
	if (v[mid] == x)
		return mid;
	else if (v[mid] < x)
		return BinarySearch1(v, mid + 1, right, x);
	else
		return BinarySearch1(v, left, mid - 1, x);
}

//循环二分查找
int BinarySearch2(vector<int>& v, int left, int right, int x)
{
	int mid = -1; 
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (v[mid] == x)
			return mid;
		else if (v[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << BinarySearch1(v, 0, 8, 10) << endl;
	cout << BinarySearch2(v, 0, 8, 10) << endl;
}
#endif