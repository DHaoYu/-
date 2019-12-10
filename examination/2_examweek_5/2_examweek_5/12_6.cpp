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
//不用加减乘除做加法
int Add(int num1, int num2)
{
	int a = num1^num2;//异或取非进位的数的和
	int b = num1&num2;//取进位数 
	if (b != 0)
	{
		a = Add(a, b <<= 1); //b在进行左移
	}
	return a;
}

int main()
{
	cout << Add(5, 3) << endl;

}
#endif

#if 0
//三角形
//需要注意的是数据类型用double

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