#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
using namespace std;

//��������
#if 0
void MyDecode(string& str)
{
	for (size_t i = 0; i<str.size(); i++)
	{
		if (str[i] <= 69 && str[i] != ' ')
		{
			str[i] += 21;
		}
		else if (str[i] == ' ')
			str[i];
		else
			str[i] -= 5;
	}
	cout << str << endl;
}



int main()
{
	string str;
	while (getline(cin, str))
		MyDecode(str);
	return 0;
}
#endif

#if 0
//�������Ӹ���
#include<set>

void DivCount(int& n)
{
	int i = 2;
	set<int> v;//����set�Ĳ��ظ��ԣ��洢���ظ�����
	while (n != 1)
	{
		if (n%i == 0)
		{
			n /= i;
			v.insert(i);
			i = 2;
		}
		else
			i++;
	}
	cout << v.size() << endl;//���size�Ĵ�С��Ϊ���Ӹ���
}

int main()
{
	int n;
	while (cin >> n)
		DivCount(n);
	return 0;
}
#endif
