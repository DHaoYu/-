#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//	cout << sizeof(unsigned) << endl;
//	int b[] = { 1, 2, 3, 4 };
//	cout << *b << endl;
//	char acX[] = "abc";//都有\0
//	char acY[] = { 'a', 'b', 'c' };//都有\0
//	char* szX = "abc";//数据区的内容不可修改
//	char* szY = "abc";
//	acX[0] = 'z';
//	//szX[1] = 'z';
//	cout << acX[3] << endl;
//	cout << acY[3] << endl;
//	cout << sizeof(acX[0]) << endl;
//	cout << sizeof(acY[0]) << endl;
//	cout << sizeof(szX) << endl;
//	cout << sizeof(szY) << endl;
//	cout << (void*)szX << " " << (void*)szY << endl;
//	//szX[1] = 'z';
//	system("pause");
//}

#if 0
#include<vector>
//排序子序列  1 2 3 2 2 1 ---> 输出2（123）（221）
//找波谷或者波峰
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i + 1] >= arr[i] && arr[i - 1] > arr[i])
			arr[i + 1] < arr[i] && arr[i - 1] < arr[i])
		{
			count++;
			if(n -1 -2 != i) //保证尾部剩两个元素，可以进行比较
				i++;
		}
	}
	cout << ++count << endl;
	return 0;
}
#endif

#if 0
//倒置字符串 i like beijing. ---> beijing. like i
#include<string>

int main()
{
	string str;
	getline(cin, str);
	int n = str.size() - 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			cout << str.substr(i + 1, n - i)<<" ";
			n = i - 1;
		}
		if (i == 0)
			cout << str.substr(i, n - i + 1) << endl;
	}
	return 0;
}
/*
py3的一行写法：
print(' '.join(input().split(' ')[:: - 1]))#input() 为输入
#第一个' '，join表示把序列拼接成字符串，连接符为空格，
#splist(' ')表示' '剪切，[:: - 1]表示从后往前遍历
*/
#endif