
#if 0
//���ʼ�   ��������
//���ֽⷨ  �ݹ� �� ����
// write your code here cpp
#include<iostream>
using namespace std;

long long arr[21] = { 0, 0, 1 };

int main()
{
	for (int i = 3; i < 21; ++i)  //����
	{
		arr[i] = (i - 1)*(arr[i - 1] + arr[i - 2]);
	}
	int n;
	while (cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}

//�ݹ�˼�룬��n���ռ��˿��Եݹ鵽n-1���ռ�����n-2���ռ���֮��
#include<iostream>
using namespace std;

long int Failrec(int n)   //din���˵Ĵ������ == n-1 ���� n-1�˵ĸ���+ n-2���˵ĸ��� 
{
	if (n<2)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;
	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		cout << Failrec(n) << endl;
	}
	return 0;
}
#endif

#if 0
//���������������
#include<iostream>
#include<vector>
using namespace std;

void MLC(vector<int>& v)
{
	vector<int> dp(v.size(), 1);
	int count = 1;
	for (size_t i = 1; i < v.size(); ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (v[i] > v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		count = max(count, dp[i]);
	}
	cout << count << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (size_t i = 0; i < n; ++i)
			cin >> v[i];
		MLC(v);
	}
}
#endif