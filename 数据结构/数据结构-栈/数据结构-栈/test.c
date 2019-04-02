#define _CRT_SECURE_NO_WARNNINGS 1
#include"Stack.h"
int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	print(&s);
	StackPush(&s, 3);
	StackPush(&s, 4);
	print(&s);
	StackPop(&s);
	StackPop(&s);
	print(&s);
	StackDestory(&s);
	return 0;
}