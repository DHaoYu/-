#define _CRT_SECURE_NO_WARNNINGS 

#include<iostream>

using namespace std;


#if 0
int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa2 = &a;
	auto& ra = a;
	auto b = a;
	cout << typeid(pa1).name() << endl;//int*
	cout << typeid(pa2).name() << endl;//int*
	cout << typeid(ra).name() << endl;// int 
	cout << typeid(b).name() << endl;//int

	return 0;
}
#endif

#if 0
int main()
{
	int arr1[] = { 1, 2, 3 };
	//auto arr2[] = { 4, 5, 6 };auto 不能用于顶级数组中
	auto parr1 = arr1;  //但是可以用作数组指针
	auto a = 1, b = 2;
	cout << *(parr1 + 1) << endl;
	//auto a = 10, b = 12.34;//同时只能赋相同类型的值
	return 0;
}
#endif

#if 0
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;

	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;

	for (auto& e : array)//范围for
		e *= 2;

	for (auto e : array)
		cout << e << endl;
}

int main()
{
	TestFor();
	return 0;
}
#endif

#if 0
void TestFunc(int array[])
{
	for (auto e : array)
		cout << e << endl;
}

int main()
{
	int* p = NULL;
	int array[10];
	TestFunc(array);
	return 0;
}
#endif

#if 0
void TestFunc(int array[])
{

	for (auto e : array)//error
		cout << e << endl;
}


int main()
{
	int* p = NULL;
	int array[] = { 1, 2, 3 };
	
	for (auto e : array)
		cout << e << endl;
	TestFunc(array);  // int*

	return 0;
}
#endif

#if 0
void TestFunc1(int a)
{
	cout << "TestFunc1(int)" << endl;
}

void TestFunc1(int* ptr)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	TestFunc1(0);
	TestFunc1(nullptr);
	return 0;
}
#endif