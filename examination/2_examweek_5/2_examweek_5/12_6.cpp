#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
int add(int a, int b)
{
	_asm
	{
		MOV EAX, a
		MOV ECX, b
		ADD EAX, ECX
	}
}
#endif

#if 0
//���üӼ��˳����ӷ�
int Add(int num1, int num2)
{
	int a = num1^num2;//���ȡ�ǽ�λ�����ĺ�
	int b = num1&num2;//ȡ��λ�� 
	if (b != 0)
	{
		a = Add(a, b <<= 1); //b�ڽ�������
	}
	return a;
}

int main()
{
	cout << Add(5, 3) << endl;

}
#endif

#if 0
//������
//��Ҫע���������������double

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	int CurMax = 0, Max = 0;
	for (int i = 0; i < array.size(); i++)
	{
		CurMax = max(array[i] + CurMax, 0);
		Max = max(CurMax, Max);
	}
	return Max;
}

int main()
{
	cout<<FindGreatestSumOfSubArray({ 1, -2, 3, 10, -4, 7, 2, -5 });
}
#endif