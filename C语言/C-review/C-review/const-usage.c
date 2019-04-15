#define _CRT_SECURE_NO_WARNNINGS

/*
对于const进行针对于指针与变量的解释
1.对于变量const只限制控制起内容不可修改
2.对于指针变量基本上以*为变化：
2.1在*号前的const 限制其不可将指针内保存的值进行修改
2.2在*号后的const 限制其不可将指针所指向的内容进行修改
*/
int main()
{
	int a1 = 1;
	int b1 = 2;
	const int a2 = a1;//与aa2相同，const定义的非指针变量在数据类型的前后
	int const aa2 = a1;//作用效果相同，都限制对其进行修改

	int *a3 = &a1;
	const int* a4 = &a1;//cosnt data,non-const pointer
	int const* a5 = &a1;//const data.non-const pointer
	int* const a6 = &a1;//non-const data,const pointer

	//int* a7 const = &a1;//表达式非法
	const int* const a8 = &a1;//non-const data,non-const pointer
	int const* const a9 = &a1;//non-const data, non-const pointer
	//a2 = 10;
	//aa2 = 10;false
	//a4 = &b1;//true
	//(*a4) = 10;false
	//a5 = &b1;//true
	//(*a5) = 10;//false
	//a6 = &b1;//false
	//(*a6) = 10;//true
	//a8 = &b1;//false
	//(*a8) = 10;//false
	//a9 = &b1;//false
	//(*a9) = 10;//false
	return 0;
}