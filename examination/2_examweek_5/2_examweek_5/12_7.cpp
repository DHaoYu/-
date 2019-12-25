#include<iostream>
#include<vector>
using namespace std;

#if 0
//奇数位上都是奇数或者偶数位上都是偶数
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0, j = 1;
	while (i<len && j<len)
	{
		if (arr[i] % 2 != 0 && arr[j] == 0)
		{
			//swap(arr[i], arr[i+1]);
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			j += 2;
			i += 2;
			continue;
		}
		if (arr[j] % 2 != 0)
			j += 2;
		if (arr[i] % 2 == 0)
			i += 2;
	}
}


void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0, j = 1;
	while (i<len&&j<len)
	{
		if (arr[len - 1] % 2 == 0)//防止越界
		{
			swap(arr[len - 1], arr[i]); 
			i += 2;
		}
		else
		{
			swap(arr[len - 1], arr[j]);
			j += 2;
		}
	}
}

int main()
{

}
#endif

#if 0
//猴子分桃
// write your code here cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n && n>0)
	{//参考的别人的
		cout << (unsigned long)pow(5, n) - 4 << " " << (unsigned long)pow(4, n) + n - 4 << endl;
	}
}
#endif