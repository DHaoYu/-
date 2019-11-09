#define _CRT_SECURE_NO_WARNNINGS 1
//#include<stdio.h>

//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}

//int main()
//{
//		fib(8);
//		printf("%d", cnt);
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1, 3, 5, 7, 9 };
//	int *p = (int*)(&a + 1); //a+1加了一个数组大小 &优先于+法
//	printf("%d, %d", *(a + 1), *(p - 1));
//}


//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s)
//	{
//		cout << s << endl;
//	}
//		~A(){}
//	};
//class B :virtual public A{
//public:
//	B(char *s1, char*s2) :A(s1){
//		cout << s2 << endl;
//	}
//	};
//class C :virtual public A{
//public:
//	C(char *s1, char*s2) :A(s1){
//		cout << s2 << endl;
//	}
//};
//class D : public B, public C{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}
#if 0
//计算糖果 A-B A+B B-C B+C已知，求ABC
#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	int x, y, z;
	cin >> a >> b >> c >> d;
	if ((a + c) % 2 == 0 && (b + d) % 2 == 0)
	{
		x = (a + c) / 2;
		y = (b + d) / 2;
		z = d - y;
		if (x < 0 || y < 0 || z < 0)
		{
			cout << "No" << endl;
			return 0;
		}
		cout << x << " " << y << " " << z << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
//将一个十进制数转换为任意进制
int main()
{
	string str, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m)
	{
		if (m < 0)
		{
			m = -m;
			cout << '-';
		}
		str = table[m % n] + str;
		m /= n;
	}
	cout << str << endl;
	return 0;
}
#endif