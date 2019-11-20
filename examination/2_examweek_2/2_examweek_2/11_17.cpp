#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;
#if 0
class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}
#endif
#if 0
class A{
public:
	void foo(){
		printf("1");
	}
	virtual void fun(){
		printf("2");
}
};
class B : public A{
public:
	void foo(){
		printf("3");
	}
	void fun(){
		printf("4");
}
};
int main(void){
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A *)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}
#endif

#if 0
//最近公共祖先
int getLCA(int a, int b) {
	/*if(a == b)
	return a;
	//递归方式写
	return a > b ? getLCA(a/2, b) : getLCA(a ,b/2);
	*/
	while (a != b)//循环方式写
	{
		if (a > b)
			a /= 2;
		if (a < b)
			b /= 2;
	}
	return a;
}
#endif

#if 0
#include<iostream>
using namespace std;
//求最大连续bit数
int main()
{
	int a;
	cin >> a;//需要循环输入
	int count = 0, max = 0;
	while (a)
	{
		if ((a & 1) == 1)
			count++;
		else
			count = 0;
		a >>= 1;
		if (max < count)
			max = count;
	}
	cout << max << endl;
}
#endif