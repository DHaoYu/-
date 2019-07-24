#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

//字符串计数
//链接：https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3?toCommentId=143013
//来源：牛客网
//
//首先要搞清楚字典序的意思：即从两个字符串的下标为0开始进行对比，字典序是从左往右进行对比的。
//例如ab，abc这样两者之间的字符串个数为aba、abb，而ab、bb两者之间的字符串个数为：
//ac、ad、ae…az、ba这26个，所以高位的字符串个数要是26的i次幂。
//其次，要理解题目的“长度在len1到len2的字符串的个数”，指的是长度在len1的字符串
//个数、长度在len1 + 1的字符串个数。。。长度为len2的字符串个数。
//例abcde、acede这两个字符串，长度为1到4表示的是长度为1的时候两个字符a、a之间的个数，
//长度为2的时候两个字符ab、ac之间的个数，长度为3的时候abc、ace两个字符串之间的个数，
//长度为4：abcd、aced的个数。
//所以计算的时候应该以长度作为变量遍历len1到len2之间的字符串个数，最后相加。

#if 0
int main()
{
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), 'z' + 1);
		vector<int> v;
		int sum = 0, dif = 0;
		for (size_t i = 0; i<len2; i++)
		{
			if (len2 >= 2 && i >= 1)
			{
				dif += s2[i - 1] - s1[i - 1];
				v.push_back(s2[i] - s1[i] + dif);
			}
			else
				v.push_back(s2[i] - s1[i]);
		}
		for (int i = 1; i<=len2; i++)
			sum += v[i - 1] * pow(26, len2 - i);
		cout << (sum % 1000007) - 1 << endl;
	}
	return 0;
}
#endif

#if 0
//牛客网down
int main(){
	//根据题中给出的例子，这个字符串只包含小写字母，不然答案就不应该是56了
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2){
		//只包含小写字母的字符串可以看成26进制的数制
		//将s1和s2补长到len2长度
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));
		vector<int> array;
		for (int i = 0; i<len2; i++){
			array.push_back(s2[i] - s1[i]);
		}
		int result = 0;
		for (int i = len1; i <= len2; i++){
			for (int k = 0; k<i; k++){
				result += array[k] * pow(26, i - 1 - k);
			}
		}
		//所有字符串最后都不包含是s2自身，所以最后要减1；
		cout << result - 1 << endl;
	}
	return 0;
}
#endif

#if 0
//最长公共子序列
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
const int N = 1024 + 10;
char str1[N], str2[N];
int dp[N][N];
int main()
{
	int n, m;
	while (scanf("%s%s", str1 + 1, str2 + 1) != EOF)
	{
		n = strlen(str1 + 1);
		m = strlen(str2 + 1);
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (str1[i] == str2[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);

		}
		printf("%d\n", dp[n][m]);
	}
}
#endif
