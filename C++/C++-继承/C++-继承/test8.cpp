#define _CRT_SECURE_NO_WARNNINGS 1
//鎂倛樟創
//剞價桶 
#include<iostream>
using namespace std;
#if 0
class A //價濬
{ 
protected:
	int _a = 1;
};

class B : public A //B樟創A
{
protected:
	int _b = 2;
};

class C : public A //C樟創A
{
protected:
	int _c = 3;
};

class D : public B, public C //D樟創B﹜C
{
public:
	void Print()
	{
		//cout << _a << endl;
		cout << &(B::_a) << endl;
		cout << &(C::_a) << endl;
	}
protected:
	int _d = 4;
};

int main()
{
	D d;
	d.Print();
}
#endif


#if 0
class A //價濬
{
protected:
	int _a = 1;
};

class B : virtual public A //B樟創A
{
protected:
	int _b = 2;
};

class C : virtual public  A //C樟創A
{
protected:
	int _c = 3;
};

class D : public B, public C //D樟創B﹜C
{
public:
	void Print()
	{
	}
protected:
	int _d = 4;
};

int main()
{
	D d;
	d.Print();
}
#endif

#if 0
class A
{
protected:
	int _a;
	int a;
};

class B : public A
{
protected:
	int _b;
};

class C : public A
{
protected:
	int _C;
};

class D : public B, public C
{
protected:
	int _d;
};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
}
#endif

#if 0
class A //價濬
{
protected:
	int _a1 = 1;
	int _a2 = 10;
};

class B : virtual public A //B樟創A
{
protected:
	int _b = 2;
};

class C : virtual public  A //C樟創A
{
protected:
	int _c = 3;
};

class D : public B, public C //D樟創B﹜C
{
protected:
	int _d = 4;
};

int main()
{
	cout << sizeof(A) << endl; //8
	cout << sizeof(B) << endl; //16
	cout << sizeof(C) << endl; //16
	cout << sizeof(D) << endl; //28
}
#endif