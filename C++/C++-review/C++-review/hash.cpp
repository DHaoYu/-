#define _CRT_SECURE_NO_WARNNINGS 

#include<iostream>


using namespace std;

#if 0
void func()
{
	int sum = 0;
	int arr[10][10][10];
	double start = clock();
	for (int i = 0; i < 10;i++)
		for (int j = 0; j < 10;j++)
			for (int k = 0; k < 10; k++)
			{
				sum += arr[i][j][k];
			}
	double end = clock();
	double cost = end - start;
	cout << cost/10000 << endl;
}

int main()
{
	func();
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void vFunc()
	{
		cout << "Base::vFunc()" << endl;
	}
	void func1(int x = 10)
	{
		cout << "Base::func1()" << endl;
	}
	void func2(double x = 1.1)
	{
		cout << "Base::func2()" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void vFunc()
	{
		cout << "Derived::vFunc()" << endl;
	}
	void func1(int x = 10)
	{
		cout << "Derived::func1()" << endl;
	}
	void func2(double x = 1.1)
	{
		cout << "Derived::func2()" << endl;
	}
};

int main()
{
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;
	pb->vFunc();
	pd->vFunc();
	
	pb->func1();
	pd->func1();

	pb->func2();
	pd->func2();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(string str = "donghaoyu", int age = 18)
	: _str(str)
	, _age(age)
	{}

private:
	string _str;
	int _age;
};


int main()
{
	Test t(" ", 18);
}
#endif

#if 0
#include<queue>

int& Funx()
{
	//int i = q.front();
	int i = 2;
	return i;
}

int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	int a = Funx();
	a = 3;
	cout << a << endl;
}
#endif


#if 0
#include<iostream>
#include<vector>
using namespace std;

bool Is24game(vector<int> v, double sum, double result)
{
	if (v.empty())
		return result == sum;

	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i];
		vector<int> b(v);
		b.erase(b.begin() + i);
		if (Is24game(b, sum, result + a)
			|| Is24game(b, sum, result - a)
			|| Is24game(b, sum, result * a)
			|| Is24game(b, sum, result / a))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	while (true)
	{
		vector<int> v;
		for (int i = 0; i < 4; i++)
		{
			int val;
			cin >> val;
			v.push_back(val);
		}
		if (Is24game(v, 24, 0))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}

#endif

int main()
{
	auto b = 4;
	int arr[] = { 1, 3, 4 };
	decltype(arr) a;
	auto c = arr;
	cout << typeid(a).name() << endl;
	cout << typeid(arr).name() << endl;
	cout << typeid(c).name() << endl;
}