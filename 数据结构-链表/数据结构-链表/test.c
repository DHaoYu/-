#include"SList.h"
#include<stdio.h>
int main()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	printSList(&s);
	return 0;
}