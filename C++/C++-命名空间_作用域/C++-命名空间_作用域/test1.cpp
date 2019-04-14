#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;


#if 0
namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return (left) + (right);
	}
}

namespace N2
{
	int a = 20;
	int b = 10;
	int Sub(int left, int right)
	{
		return (left) - (right);
	}
	namespace N3
	{
		int a = 10;
		int b = 10;
		int Div(int left, int right)
		{
			if (0 == (right))
				return false;
			return (left)/(right);
		}
	}
}

namespace N4
{
	int c = 10;
	int b = 100;

	int Mul(int left, int right)
	{
		return (left) * (right);
	}
}

int main()
{
	N4::Mul(2, 4);
	N1::Add(3, 5);
	N2::N3::Div(10, 2);
	printf("%d \n", N2::N3::a);
	return 0;
}
#endif


#if 0
namespace N1
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return (left)+(right);
	}
}

namespace N2
{
	int a = 20;
	int b = 10;
	int Sub(int left, int right)
	{
		return (left)-(right);
	}
	namespace N3
	{
		int a = 10;
		int b = 10;
		int Div(int left, int right)
		{
			if (0 == (right))
				return false;
			return (left) / (right);
		}
	}
}

namespace N4
{
	int c = 10;
	int b = 100;

	int Mul(int left, int right)
	{
		return (left)* (right);
	}
}

namespace N1
{
	int c = 9;
	int d = 10;
}
int main()
{
	N4::Mul(2, 4);
	N1::Add(3, 5);
	N2::N3::Div(10, 2);
	printf("%d \n", N2::N3::a);
	N1::d;//如果编译器中存在两个相同的命名空间，则编译器会将其合成一个
	
	return 0;
}
#endif

#if 0
namespace N1
{
	int c = 30;
	int d = 40;
	int Div(int left, int right)
	{
		return left / right;
	}
}

using namespace N1;//作用域说明符，这句话可以省去：：


int main()
{
	printf("%d ", Div(10,2));
	return 0;
}
#endif

#if 0
int main()
{
	int a = 0;
	cin >> a;

	double d;
	cin >> d;

	cout << "change world!" << endl;
	cout << 10 << " " << 12.34 << " " << a << endl;

	return 0;
}
#endif




