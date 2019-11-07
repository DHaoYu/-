#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
int main()
{
	char a1[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 };
	char* a2 = "1234567";
	//a2[1] = 'c';//不可修改
	char a3[] = { "123" };

	char *p;
	int i = 8;
	p = a1 + i;
	printf("%c\n", *(p - 3));

}
#endif

#include<string>
#if 0
//字符串中找出连续最长的数字串
int main()
{
	string str;
	getline(cin, str);
	int maxlen = 0, len = 0;
	int begin = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			len++;
		if (maxlen < len)
		{
			maxlen = len;
			begin = i - len + 1;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
			len = 0;
	}
	cout << str.substr(begin, maxlen) << endl;
	return 0;
}
#endif

#include<vector>
#include<algorithm>
//数组中出现 次数超过一般的数字
#if 0
int main()
{
	vector<int> numbers{ 1, 2, 3, 2, 2, 2, 5, 4, 3,3,3,3,3 };
	
	sort(numbers.begin(), numbers.end());
	size_t count = 1, max = 1;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		if (numbers[i] != numbers[i + 1])
		{
			if (max < count)
				max = count;
			count = 1;
		}
		else
			count++;
		//if (numbers[i] == numbers[i + 1])
		//{
		//	count++;
		//	if (max < count)
		//	{
		//		max = count;
		//		num = numbers[i];
		//	}
		//}
		//else
		//	count = 1;
	}
	if (max >= numbers.size() / 2)
		cout << numbers[numbers.size() / 2];
	else
		cout<<0;
}


int main()
{
	vector<int> numbers{ 1, 2, 3, 2, 2, 2, 5, 4,2};
	sort(numbers.begin(), numbers.end());
	int index = numbers.size() / 2;
	for (int i = 0; i < index +1; i++)
	{
		if (numbers[i] == numbers[i + index])
			cout << numbers[i];
	}
	cout << 0;
	return 0;
}
#endif