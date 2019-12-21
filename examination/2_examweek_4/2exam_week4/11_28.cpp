#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//字符串反转
//reverse

#if 0
//计算最长字串的长度
//bacefaebcdfabfaadebdaacabbdabcfffbdcebaabecefddfaceeebaeabebbad
//dedcecfbbbecaffedcedbadadbbfaafcafdd
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int maxlen = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = s1.size(); j > i; j--)
			{
				if (s2.find(s1.substr(i, j - i)) != -1 &&
					j - i > maxlen)
				{
					maxlen = j - i;
				}
			}
		}
		cout << maxlen << endl;
	}
}
#endif


