#if 0
#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<array>

using namespace std;

//array 不能够自行改变大小
int main()
{
	array<int, 3> a1 = { 1, 2, 3 };
	array<int, 2> a2 = { 4, 5 };
	//a1.swap(a2);进行交换时，也许要大小一致

}
#endif