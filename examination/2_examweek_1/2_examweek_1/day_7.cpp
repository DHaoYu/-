#define _CRT_SECURE_NO_WARNNINGS 1
#include<stdio.h>
#if 0
struct One{
	double d;
	char c;
	int i;
};
struct Two{
	char c;
	double d;
	int i;
};
#include<iostream>
using namespace std;

int main()
{
	//int x = 1;
	//do{
	//	printf("%2d\n", x++);
	//} while (x--);
	cout << sizeof(One) <<sizeof(Two)<< endl;

}
#endif

#if 0
#include<iostream>
using namespace std;
class B0//����B0����
{
public://�ⲿ�ӿ�
	virtual void display()//̓ ��Ա����
	{
		cout << "B0: :display0" << endl;
	}
};
class B1 :public B0//��������
{
public:
	void display() { cout << "B1: :display" << endl; }
};
class D1 : public B1//��������
{
public:
	void display(){ cout << "D1: :display0" << endl; }
};
void fun(B0 ptr)//��ͨ����
{
	ptr.display();
}
int main()//������
{
	B0 b0;//������������ָ��
	B1 b1;//�������������
	D1 d1;//�������������
	fun(b0);//���û���B0������Ա 
	fun(b1);//����������B1������Ա
	fun(d1);//����������D1������Ա
	//ȫ����B0
}
#endif

#if 0
//ͳ�ƻ���  s1 = aba s2 = b ��s2����s1�У��ж�Ϊ���ĵĸ���
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool IsRestr(string &s1)
{
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1 == s2)
		return true;
	else
		return false;
}

int main()
{
	string s1, s2;
	int count = 0;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		string str = s1;
		str.insert(i, s2);
		if (IsRestr(str))
			count++;
	}
	cout << count << endl;
}
#endif
//��������   3 -1 2 1 ---> 4
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, maxsum = -1000000000, sum = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		if (sum > maxsum)
			maxsum = sum;
		if (sum < 0)
			sum = 0;
	}
	cout << maxsum << endl;
}