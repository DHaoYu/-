#define _CRT_SECURE_NO_WARNNINGS 1
/*  线性链表
1. 线性表 有两种：顺序表和链表
链表中的线性链表为：用指针实现的，存储顺序与逻辑顺序
一般来说，在线性表的链式存储结构中，各数据结点的存储序号是不连续的，
并且各结点在存储空间中的位置关系与逻辑关系也不一致。
线性链表中数据的插入和删除都不需要移动表中的元素，只需改变结点的指针域即可
*/

#if 0
//汽水瓶
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int m = 0, x = 0;
		while (n > 1)
		{
			if (n == 2)
				n += 1;
			x = n / 3;
			n = x + n % 3;
			m += x;
		}
		cout << m << endl;
	}
	//cout<<(n/2)<<endl; //根据数学推导出结果
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		if (s1.size() < s2.size())
			swap(s1, s2);
		int maxlen = 0;
		string str;
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s2.size(); j++)
			{
				int k = i;
				while (s1[k++] == s2[j++])
					;
				if (maxlen < k - i - 1)
				{
					maxlen = k - i - 1;
					str = s1.substr(i, maxlen);
				}
			}

		}
		cout << str << endl;
	}
	return 0;
}
#endif
#if 0
#include<string>
#include<iostream>
using  namespace std;

int main()
{
	string str = "12343543";
	cout << str.substr(0, 1);
}
#endif