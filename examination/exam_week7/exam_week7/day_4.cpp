#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
//�����г��ִ�������һ�������
class Solution {
public:
	void MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		size_t i = 0, sum = 0, j = numbers.size();
		while (i<numbers.size())
		{
			j = numbers.size()-1;
			for (; j>i; j--)
			{
				if (numbers[j] == numbers[i])
				{
					sum = j - i + 1;
					break;
				}
			}
			if (sum > (numbers.size() / 2))
			{
				cout << numbers[i];
				return;
			}
			i = j + 1;
		}
		cout<< 0;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1, 1, 1, 2, 2, 2, 1, 0, 2 };
	s.MoreThanHalfNum_Solution(v);
	return 0;
}
//---------------------------------------
//˼·����������м��Ԫ�رض��ǳ��ִ�������һ���Ԫ�أ�������һ�㣬����ѭ������
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		size_t count = 0;
		int midNum = numbers[numbers.size() / 2];
		for (size_t i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == midNum)
				count++;
		}
		return count>(numbers.size() / 2) ? midNum : 0;
	}
};
#endif



