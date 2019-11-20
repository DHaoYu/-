#define _CRT_SECURE_NO_WARNNINGS 1

#if  0
int main()
{
	int a1[2][2] = { { 1 }, { 2 } };
	int a2[][2] = { 1, 2, 3, 4 };
	int a3[2][2] = { { 1 }, 2, 3 };
	//int a4[2][] {{ 1, 2 }, { 3, 4 }};error
 	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void x()
	{
		cout << "B" << endl;
	}
	~Base()
	{
		delete this;
		//this = nullptr;
	}
};

class D : public Base
{
public:
	void x()
	{
		cout << "D" << endl;
	}
};
int main()
{
	D d;
	d.x();
}
#endif
#if 0
#include "stdio.h"
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived : public Base{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));
	printf("%d,", pObj->Bar(100));
	printf("%d,", pObj->Bar('a'));
	printf("%d,", Obj.Bar(100));
	printf("%d,", Obj.Bar('a'));
}
#endif

#if 0
#include<iostream>
using namespace std;

//二进制插入
int binInsert(int n, int m, int j, int i) {
	// write code here
	m <<= j;
	return n + m;
}

int main()
{
	cout<<binInsert(1024, 19, 2, 6);
}
#endif

#if 0
#include<iostream>
using namespace std;
//查找组成一个偶数最接近的两个素数
bool IsPrime(int n)
{
	int i = 1;
	while (++i != (n / 2))
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int left, right;
		left = right = n / 2;
		while (left)
		{
			if (IsPrime(left) && IsPrime(right))
			{
				cout << left << endl << right << endl;
				break;
			}
			else
			{
				left--;
				right++;
			}
		}
	}
}
#endif

#if 0
#include<iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int temp = 0;
	while (y != 0)//辗转相除法
	{
		temp = y;
		y = x%y;
		x = temp;
	}
	cout << x;
}
#endif