#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//�ַ�����ת
//reverse

#if 0
//������ִ��ĳ���
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


