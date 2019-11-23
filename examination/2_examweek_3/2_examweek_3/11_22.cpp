#define _CRT_SECURE_NO_WARNNINGS 1
//#include<stdio.h>
#if 0
static int a = 1;//全局变量
void fun1(void){
	a = 2;
}
void fun2(void){
	int a = 3;
}
void fun3(void){
	static int a = 4; //局部变量，但是延长变量的生命周期
}
int main(){
	static int a = 1;
	printf("%d", a);
	fun1();
	printf("%d", a);
	fun2();
	printf("%d", a);
	fun3();
	printf("%d", a);
}
#endif

/*
C++中关于堆和栈的说法，哪个是错误的:
A 堆的大小仅受操作系统的限制，栈的大小一般一般较小
B 在堆上频繁的调用new/delete容易产生内存碎片，栈没有这个问题
C 堆和栈都可以静态分配
D 堆和栈都可以动态分配

选C，静态分配是指在编译阶段就能确定大小，由编译器进行分配，堆不可以进行静态分配，堆的申请都是在执行过程中进行的。
A，堆和栈的大小都可以设置，栈一般只有几KB。
B，堆在动态分配时，要申请连续的内存空间，释放后会产生碎片。
D，堆是使用malloc()、calloc()、realloc()等函数动态分配的，而使用alloca()函数可以动态分配栈的内存空间，释放的时候由编译器自己释放
*/
#if 0
#include<iostream>
using namespace std;
/*
//基本做法----移位操作
int main()
{
int x;
while(cin>>x)
{
int count = 0;
while(x)
{
if(x & 1 == 1)
count++;
x>>=1;
}
cout<<count<<endl;
}
return 0;
}
*/
#include<bitset>
int main()
{//使用bitset
	int n;
	while (cin >> n){
		bitset<32> bs(n);
		cout << bs.count() << endl;
	}
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
/*
1. 先把手套为0（匹配肯定不成功的）的这种最坏情况全部拿出来
2. 找出两个数组中最小和（不包括0手套的）数组，把该数组中最大的手套依次
   全拿了，剩下最小的，拿一个
3. 再从多的数组中，拿出随便一个，就可以匹配
*/
int findMinimum(int n, vector<int> left, vector<int> right)
{
	int min = 0, lmin = 0, rmin = 0;
	int lm = 27, rm = 27;
	for (int i = 0; i < n; i++)
	{
		if (left[i] == 0 || right[i] == 0)
		{
			min += left[i];
			min += right[i];
		}
		else
		{
			lmin += left[i];
			rmin += right[i];
			if (left[i] < lm)
				lm = left[i];
			if (right[i]< rm)
				rm = right[i];
		}
	}
	min += lmin > rmin ? (rmin - rm) : (lmin - lm);
	return min + 2;
}

int main()
{
	//8,[2,1,1,4,7,2,3,1],[0,0,0,1,0,1,0,0] ---18
	vector<int> left = { 2, 1, 1, 4, 7, 2, 3, 1 };
	vector<int> right = { 0, 0, 0, 1, 0, 1, 0, 0 };
	cout << findMinimum(8, left, right) << endl;
	vector<int> left1 = { 0, 7, 1, 6 };
	vector<int> right1 = { 1, 5, 0, 6};
	cout << findMinimum(4, left1, right1);
}
#endif