#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

//�ַ�������
//���ӣ�https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3?toCommentId=143013
//��Դ��ţ����
//
//����Ҫ������ֵ������˼�����������ַ������±�Ϊ0��ʼ���жԱȣ��ֵ����Ǵ������ҽ��жԱȵġ�
//����ab��abc��������֮����ַ�������Ϊaba��abb����ab��bb����֮����ַ�������Ϊ��
//ac��ad��ae��az��ba��26�������Ը�λ���ַ�������Ҫ��26��i���ݡ�
//��Σ�Ҫ�����Ŀ�ġ�������len1��len2���ַ����ĸ�������ָ���ǳ�����len1���ַ���
//������������len1 + 1���ַ�����������������Ϊlen2���ַ���������
//��abcde��acede�������ַ���������Ϊ1��4��ʾ���ǳ���Ϊ1��ʱ�������ַ�a��a֮��ĸ�����
//����Ϊ2��ʱ�������ַ�ab��ac֮��ĸ���������Ϊ3��ʱ��abc��ace�����ַ���֮��ĸ�����
//����Ϊ4��abcd��aced�ĸ�����
//���Լ����ʱ��Ӧ���Գ�����Ϊ��������len1��len2֮����ַ��������������ӡ�

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
//ţ����down
int main(){
	//�������и��������ӣ�����ַ���ֻ����Сд��ĸ����Ȼ�𰸾Ͳ�Ӧ����56��
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2){
		//ֻ����Сд��ĸ���ַ������Կ���26���Ƶ�����
		//��s1��s2������len2����
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
		//�����ַ�����󶼲�������s2�����������Ҫ��1��
		cout << result - 1 << endl;
	}
	return 0;
}
#endif

#if 0
//�����������
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
