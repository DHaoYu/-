
/*
1.do--while循环的先后顺序，输出数字的格式
2.结构体大小，以及pragma pack（4&8）下的大小
3.strcpy 和strcat 用法 & 指针的移动
4.二维数组和指向数组的指针的用法
5.输入出格式的用法
6.复杂一些格式的容器---unordered_map priority_queue
7.类中默认函数
8.指针对象/对象构造和析构的次数
9.类的重载和多态
10.类中的继承
*/

#if 0
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Isre_String(string& s1,string& s2)
{
	int count = 0;
	for (size_t i = 0; i < s1.size() + 1; i++)
	{
		string sTemp1(s1);
		sTemp1.insert(i,s2);
		string sTemp2(sTemp1);
		reverse(sTemp2.begin(), sTemp2.end());

		if (sTemp1.compare(sTemp2)==0)
			count++;
	}
	cout << count << endl;
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	Isre_String(s1, s2);

	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;

void Sub_Max(vector<int>& v, int n)
{
	int max = v[0];
	int temp = v[0];
	for (int i = 0; i<n; i++)
	{
		temp = v[i];
		for (int j = i; j < n; j++)
		{
			if (j>i)
			temp += v[j];
			if (temp > max)
			{
				max = temp;
			}
		}
	}
	cout << max << endl;
}


int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> v(n);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	Sub_Max(v, n);
	return 0;
}
#endif