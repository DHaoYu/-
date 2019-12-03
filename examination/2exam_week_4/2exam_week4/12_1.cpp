#if 0 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//微信红包
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

//计算字符串的距离
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
//网上的答案
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
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));/*dp[x][y]代表将a字符串的前x个字符（从1编号，a的前1个字符为a[0],
														 前两个字符为a[0]和a[1]）转换成b字符串的前y个字符*/
		for (int i = 0; i <= n; i++) dp[i][0] = i;
		for (int j = 0; j <= m; j++) dp[0][j] = j;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; ++j)
		{
			int d1 = dp[i - 1][j] + 1, d2 = dp[i][j - 1] + 1, d3 = dp[i - 1][j - 1];
			if (a[i - 1] != b[j - 1]) d3 += 1; //注意由于a的前i-1个字符时从1编号，则第i个字符也是从1编号，为a[i-1]，同理b[j-1]
			dp[i][j] = min(min(d1, d2), d3);
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
#endif