
/*
1.do--whileѭ�����Ⱥ�˳��������ֵĸ�ʽ
2.�ṹ���С���Լ�pragma pack��4&8���µĴ�С
3.strcpy ��strcat �÷� & ָ����ƶ�
4.��ά�����ָ�������ָ����÷�
5.�������ʽ���÷�
6.����һЩ��ʽ������---unordered_map priority_queue
7.����Ĭ�Ϻ���
8.ָ�����/������������Ĵ���
9.������غͶ�̬
10.���еļ̳�
*/

#if 0
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Isre_String(string& s1,string& s2)
{
	int count = 0;
	for (size_t i = 0; i < s1.size() + 1; i++)
	{
		string sTemp1(s1);
		sTemp1.insert(i,s2);
		string sTemp2(sTemp1);
		reverse(sTemp2.begin(), sTemp2.end());

		if (sTemp1.compare(sTemp2)==0)
			count++;
	}
	cout << count << endl;
}

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	Isre_String(s1, s2);

	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;

void Sub_Max(vector<int>& v, int n)
{
	int max = v[0];
	int temp = v[0];
	for (int i = 0; i<n; i++)
	{
		temp = v[i];
		for (int j = i; j < n; j++)
		{
			if (j>i)
			temp += v[j];
			if (temp > max)
			{
				max = temp;
			}
		}
	}
	cout << max << endl;
}


int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<int> v(n);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	Sub_Max(v, n);
	return 0;
}
#endif