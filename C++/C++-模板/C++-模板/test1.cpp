#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


#if 0
//函数模板---在使用时进行参数化，编译器推演出函数的参数类型
template<class T>//typename是定义模板的关键字，也可以使用class来代替
void Swap(T a, T b)	//但是class不能使用struct代替
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	cout << a << b << endl;
	double c = 2.0, d = 1.2;
	Swap(c, d);
	cout << c << d << endl;
	char e = 'a', f = 'b';
	Swap(e, f);
	cout << e << f << endl;
	//Swap(a, c);//发现模板里面只有一种类型，所以在传入两种不同类型的参数时，
	//cout << a << d << endl;//编译器将无法推演两种类型
	//Swap<int>(e, a);
	Swap(a, (int)c);//强转的变量不能被强转类型所引用
	return 0;
}
#endif

#if 0
template<class T> 
T Add(const T& left, const T& right) 
{
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	/*     该语句不能通过编译，因为在编译期间，当编译器看到该实例化时
	，需要推演其实参类型
	通过实参a1将T推演为int，通过实参d1将T推演为double类型，
	但模板参数列表中只有一个T，
	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，
	编译器就需要背黑锅     Add(a1, d1);    */
	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化 
	Add(a1, (int)d1);
	return 0;
}
#endif

#if 0
int main()
{
	double b = 1.2;
	int a = 0;
	//int& a = (int)b;
	int& c = a;
	//int e = (int)b;可将其强转之后先赋值给其他int变量，然后进行引用
	//int& d = (int)b;error 强制转化的值无法被引用
	int& d = (int)b; //非常量引用的初始值必须为左值
	//变量为左值，常量为右值
	return 0;
}
#endif

#if 0
//函数模板的实例化
//隐式实例化--->编译器根据实参的类型推演出函数模板参数的实际类型
template<class T>
T Add(const T left, const T right)
{
	return left + right;
}

int main()
{
	cout << Add(1.0, 2.1) << endl;//隐式实例化
	return 0;
}
#endif

#if 0
//显式实例化--->用户自己在调用函数的后面加上<Typename（数据类型）>进行显式实例化
template<class T>
T Add(const T left, const T right)
{
	return left + right;
}

int main()
{
	Add<double>(1.0, 2.10);
	cout << Add<int>(1.1, 2.10) << endl;//显式实例化编译器直接将类型不符合的
			//进行类型转化，改为可以在用户填写的类型,无法转化就会报错
	return 0;
}
#endif 

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)//可以存在同名的模板函数和非模板函数
{
	return left + right;
}

int main()
{
	//Add<int>(1.0, 2);//只有在模板存在的情况下才可以添加类型
	cout << Add<double>(1.0, 2.1) << endl;
	cout << Add(1, 2) << endl;//与模板类型一致，所以编译器将不会特化其，
					//调用用户写的那份add函数
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}


template<class T>
T Add(T left, T right)//可以存在同名的模板函数和非模板函数
{
	return left + right;
}

int main()
{
	cout<<Add(1.1, 2.1);//将其强制转化为int型调用Add函数
	//但是如果有模板函数的话，由于模板函数可以更匹配该类型参数，所以调用模板函数
	return 0;
}
#endif