#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
#include<iostream>
using namespace std;
//����ӷ�---���������������
int addAB(int A, int B) {
	// write code here
	int temp = A & B;
	while (B != 0)
	{
		temp = A & B;
		A = A ^ B;
		temp <<= 1;
		B = temp;
	}

	return A;
}
int main()
{
	cout<<addAB(13, 25);
}
//���ϴ���
int addAB(int A, int B) {
	// write code here
	int temp;
	do{
		temp = A & B;
		A = A ^ B;
		B = temp << 1;
	} while (B != 0);
	return A;
}
#endif
#if 0
//201301 JAVA ��Ŀ2-3��
#include<iostream>
using namespace std;

int func(int m, int n)
{
	if (m == 0 || n == 0)
		return 1;
	return func(m - 1, n) + func(m, n - 1);
}

int main()
{
	int m, n;
	while(cin >> m >> n)
		cout << func(m, n) << endl;
}
#endif
