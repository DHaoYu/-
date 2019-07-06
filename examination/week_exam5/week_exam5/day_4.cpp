#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#if 0
//����������ǵ�������λ��ż��λ��Ȼ������������һλ�����бȽϽ�����
//��������ʹÿһ�����һλ�����£�����odd��evenÿ�ζ����������ƶ���ֱ���ƶ���
//���һ��λ�ã�����ѭ�����������
class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int odd = 1;
		int even = 0;
		while (int i = len-1)
		{
			if (arr[i] % 2 == 0)
			{
				swap(arr[i], arr[even]);
				even += 2;
				i += 1;
			}
			else
			{
				swap(arr[i], arr[odd]);
				odd += 2;
				i += 1;
			}
			if (odd == i || even == i)
				break;
		}
	}
};

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5 };
	Solution s;
	s.oddInOddEvenInEven(arr, 5);
	for (auto e : arr)
		cout << e << " ";
	return 0;
}
#endif


#if 0
//Ƕ��ѭ����ʱ�临�Ӷȹ���
void MonkeyDP(int n)
{
	int x = 1;
	while (1)
	{
		int m = n;
		int temp = x;
		while (m--)
		{
			if (temp % 5 != 1)
				break;
			else
			{
				temp = temp / 5;
				temp *= 4;
			}
			if (m == 0)
			{
				cout << x << " " << n + temp << endl;
				return;
			}

		}
		x += 5;
	}
	return;
}


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		MonkeyDP(n);
	}

	return 0;
}
#endif
