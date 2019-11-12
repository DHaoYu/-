#define _CRT_SECURE_NO_WARNNINGS 1

//#include<iostream>
//using namespace std;
//char fun(char x, char y) {
//	return y;
//}
//int main() {
//	int a = '1', b = '2', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

#if 0
//不要二  将欧几里得距离（勾股距离）为2的地方不放蛋糕
#include<iostream>
using namespace std;

int a[1000][1000];
int count = 0;
int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] != -1)
			{
				count++;
				if (i + 2 < h)//防止越界
					a[i + 2][j] = -1;
				if (j + 2 < w)//防止越界
					a[i][j + 2] = -1;
			}
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#if 0
//把字符串转换成整数  ,如果字符串中有字母，则返回0
//+12343--->12343	-1233421--->-1233421	
#include<iostream>
#include<string>
using namespace std;


int StrToInt(string str) {
	int n = str.size(), s = 1;
	long long ret = 0;
	if (str[0] == '-')
		s = -1;
	for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < n; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		ret = ret * 10 + str[i] - '0';
	}
	return ret * s; //s为正负标志
}

int main()
{
	cout << StrToInt("-12315689") << endl;
}
#endif
