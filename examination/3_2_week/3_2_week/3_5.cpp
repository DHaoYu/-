#if 0
//�ռ����б�
// write your code here cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar(); //ˢ�»�����
		while (n--)
		{
			string str;
			getline(cin, str);
			if (str.find(',') != -1 || str.find(' ') != -1)
			{
				str.insert(str.begin(), '"');
				str.insert(str.end(), '"');
			}
			if (n == 0)
				cout << str << endl;
			else
				cout << str << ", ";
		}
	}
	return 0;
}
#endif

#if 0
//������
// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<long> v(91, 1);
	v[1] = 1;
	for (int i = 2; i < v.size(); i++)
		v[i] = v[i - 1] + v[i - 2];
	int n;
	while (cin >> n)
		cout << v[n] << endl;
	return 0;
}
#endif

#if 0
//�����쿪ʼ��2������
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<long> v(91, 1);
	v[1] = 1;
	for (int i = 2; i < v.size(); i++)
	{
		if (i >= 5)
			v[i] = v[i - 1] + v[i - 2] + v[i - 4];
		else
			v[i] = v[i - 1] + v[i - 2];
	}
		int n;
	while (cin >> n)
		cout << v[n] << endl;
	return 0;
}
#endif
#include<vector>
using namespace std;

void ShortPath(vector<vector<int>> v, int n)
{
	vector<int> dp(n, 999);
	dp[0] = v[0][1];
	for (int i = 0; i < n; i++)
	{

	}
}