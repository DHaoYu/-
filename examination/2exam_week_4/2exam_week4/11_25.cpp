#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
#if 0
void increment_ints(int p[], int n){
	assert(p != NULL); /* 确保p不为空指针*/
	assert(n >= 0); /* 确保n不为负数*/
	while (n){ /* 循环n次。*/
		*p++;					//运算符优先级 ++ > *
		/*增大p*/
		p++, n--;
		/* p指向下一位，n减1 */
	}
}

int main()
{
	int arr[] = { 1, 2, 3 };
	increment_ints(arr, 3);
	return 0;
}
#endif
#if 0
//统计每个月兔子的总数
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int i, a = 1, b = 0, sum = 1;
		if (n < 3)
			cout << sum << endl;
		else
		{
			while (n >= 3)
			{
				b = a;
				a = sum;
				sum = a + b;
				n--;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
#endif


