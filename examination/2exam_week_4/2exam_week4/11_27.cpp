#define _CRT_SECURE_NO_WARNNINGS 1
/*  ��������
1. ���Ա� �����֣�˳��������
�����е���������Ϊ����ָ��ʵ�ֵģ��洢˳�����߼�˳��
һ����˵�������Ա����ʽ�洢�ṹ�У������ݽ��Ĵ洢����ǲ������ģ�
���Ҹ�����ڴ洢�ռ��е�λ�ù�ϵ���߼���ϵҲ��һ�¡�
�������������ݵĲ����ɾ��������Ҫ�ƶ����е�Ԫ�أ�ֻ��ı����ָ���򼴿�
*/

#if 0
//��ˮƿ
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int m = 0, x = 0;
		while (n > 1)
		{
			if (n == 2)
				n += 1;
			x = n / 3;
			n = x + n % 3;
			m += x;
		}
		cout << m << endl;
	}
	//cout<<(n/2)<<endl; //������ѧ�Ƶ������
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		if (s1.size() < s2.size())
			swap(s1, s2);
		int maxlen = 0;
		string str;
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s2.size(); j++)
			{
				int k = i;
				while (s1[k++] == s2[j++])
					;
				if (maxlen < k - i - 1)
				{
					maxlen = k - i - 1;
					str = s1.substr(i, maxlen);
				}
			}

		}
		cout << str << endl;
	}
	return 0;
}
#endif
#if 0
#include<string>
#include<iostream>
using  namespace std;

int main()
{
	string str = "12343543";
	cout << str.substr(0, 1);
}
#endif