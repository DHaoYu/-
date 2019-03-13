
#include<stdio.h>

void Swop(int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Swop1(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10, b = 20;
	printf("a = %d , b = %d\n", a, b);
	Swop(&a, &b);
	printf("a = %d , b = %d\n", a, b);
	Swop1(a, b);
	printf("a = %d , b = %d\n", a, b);
	return 0;
}