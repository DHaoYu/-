
#if 0
//��̬������̨��
#include<iostream>
using namespace std;

int jumpFloorII(int number) 
{
	return 1 << (--number);
}
#endif


#if 0
//�쵽������
#include<iostream>
using namespace std;

int main()
{
	//pr >= n
	double n, r;
	while (cin >> n >> r)
	{
		if (n / 6.28 > r)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
#endif