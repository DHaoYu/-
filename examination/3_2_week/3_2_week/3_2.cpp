

//分解因数
#include<iostream>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int i = 2;
		cout << num << " = ";
		while (num > 1)
		{
			if (num % i == 0)
			{
				if (i == num)
					cout << i << endl;
				else
					cout << i << " * ";
				num /= i;
				i = 2;
			}
			else
				i++;
		}
	}
	return 0;
}

//求美国节日 