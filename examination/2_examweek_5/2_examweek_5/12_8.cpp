#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;
#if 0
int main()
{
a:1;  //a: 表示标签，//表示注释
	http://www.taobao.com
	cout << "a" << endl;
	return 0;
}
#endif

#if 0
#include<vector>
#include<set>
/**
* 正数数组中的最小不可组成和
* 输入：正数数组arr
* 返回：正数数组中的最小不可组成和
*/
int getFirstUnFormedNum(vector<int> arr, int len) {
	set<int> s;
	s.insert(arr[0]);
	for (int i = 1; i < len; i++)
	{
		auto it = s.begin();
		set<int> t(s);
		while (it != s.end())
			t.insert(*(it++) + arr[i]);
		t.insert(arr[i]);
		s = t;
	}
	auto it = s.begin();
	while (it != --s.end()) {
		int t = *(it++);
		if (*it != t + 1)
			return t + 1;
	}
	return *it + 1;
}

int main()
{
	cout<<getFirstUnFormedNum({ 3, 2, 5 }, 3);
}
#endif

#if 0
//有假币
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int temp = n;
		int count = 0;
		while (temp>2)//error
		{
			temp >>= 1;
			count++;
		}
		cout << count-1 << endl;
		count = 0;
		while (n>1)
		{
			n = n / 3 + 1 - (n % 3 ^ 3) / 3;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
#endif