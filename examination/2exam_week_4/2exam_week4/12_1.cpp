#if 0 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//΢�ź��
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == gifts[n / 2])
				count++;
		}
		if (count > n / 2)
			return gifts[n / 2];
		else
			return 0;
	}
};

int main()
{

}
#endif

#if 0

//�����ַ����ľ���
//ganxioafstgdpceecubqrngumbpjvwxdpzmragsunvfnmejbcvsoydtbbewybygpsmmyjuvezn
//ixfkieaaocalmxhfifyadnouljtezrnpnfoenespcaenyvzcjtppsaxegmeytqrkvdwugvouskcnnqnmhepquncvyvgkansquaotkgvlvplktrabaikeuubfupunpztpvvzdqaqgfmtzxlcxsipltzwjegpqjzclclvjsmqbmiyzvcujpvhupyhvhhjq
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		for (int i = 0; i < (s1.size()>s2.size() ? s2.size() : s1.size()); i++)
		{
			if (s1[i] != s2[i])
				count++;
		}
		count += abs((int)(s1.size() - s2.size()));
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
//���ϵĴ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	string a, b;
	while (cin >> a >> b)
	{
		int n = a.size(), m = b.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));/*dp[x][y]����a�ַ�����ǰx���ַ�����1��ţ�a��ǰ1���ַ�Ϊa[0],
														 ǰ�����ַ�Ϊa[0]��a[1]��ת����b�ַ�����ǰy���ַ�*/
		for (int i = 0; i <= n; i++) dp[i][0] = i;
		for (int j = 0; j <= m; j++) dp[0][j] = j;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; ++j)
		{
			int d1 = dp[i - 1][j] + 1, d2 = dp[i][j - 1] + 1, d3 = dp[i - 1][j - 1];
			if (a[i - 1] != b[j - 1]) d3 += 1; //ע������a��ǰi-1���ַ�ʱ��1��ţ����i���ַ�Ҳ�Ǵ�1��ţ�Ϊa[i-1]��ͬ��b[j-1]
			dp[i][j] = min(min(d1, d2), d3);
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
#endif