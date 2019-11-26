#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;
#if 0
struct Test{
	Test(int){}
	Test(){}
	void Func()
	{}
};

int main()
{
	Test a(1);
	Test b;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	int a[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("%p\n%p\n%p\n", *(a + 1), a + 1 + 1, *(a + 1) + 1);
	printf("%d, %d", sizeof(*(a + 1)), sizeof(a + 1));
	int i = 0;
	printf("%d", ++i);
	printf("%d", ++i);
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

bool PerfectNum(int n)
{
	int i = 1, num = 0;
	while (i != n)
	{
		if (n % i == 0)
		{
			num += i;
		}
		i++;
	}
	if (num == n)
		return true;
	else
		return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i <= n; i++)
		{
			if (PerfectNum(i))
				count++;
		}
		cout << count << endl;
	}
}
#endif
#if 0
//扑克牌大小
#include<string>
#include<iostream>
using namespace std;

//int main()
//{
//	string str = "10234310342210";
//	while (str.find("10") != -1)
//		str.replace(str.find("10"), 2, "T");
//	cout << str << endl;
//}
//

#include<algorithm>
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
			break;
		}
		string str1 = str.substr(0, str.find('-'));
		string str2 = str.substr(str.find('-') + 1);
		string read = "345678910JQKA2";
		int count1 = count(str1.begin(), str1.end(), ' ');
		int count2 = count(str2.begin(), str2.end(), ' ');
		if (count1 == 3 && count2 != 3)
			cout << str1 << endl;
		else if (count2 == 3 && count1 != 3)
			cout << str2 << endl;
		else if (count1 != count2)
			cout << "ERROR" << endl;
		else
		if (read.find(str1[0]) > read.find(str2[0]))
			cout << str1 << endl;
		else
			cout << str2 << endl;
	}
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
class A{
public:
	~A() {
		cout << "~A()";
	}
};
class B{
public:
	virtual ~B() {
		cout << "~B()";
	}
	};
class C : public A, public B {
	public:
		~C() {
			cout<< "~C()";
		}
};
int main() {
		C* c = new C;
		B * b1 = dynamic_cast<B *>(c);//随意更改动态类型，会导致多态调用出现问题
		A * a2 = dynamic_cast<A *>(b1);
		delete a2;
	}
#endif
