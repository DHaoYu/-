#define _CRT_SECURE_NO_WARNNINGS 1
#include "SList.h"

int main()
{
	SList s;
	SList q;
	Node * d;
	SListInit(&s);
	SListInit(&d);
	SListInit(&q);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 2);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(d, 1);
	SListPushBack(d, 2);
	SListPushBack(d, 2);
	SListPushBack(d, 2);
	SListPushBack(d, 3);
	SListPushBack(d, 3);
	Del(d);
	SListPushBack(&q, 2);
	SListPushBack(&q, 3);
	SListPushBack(&q, 4);
	//mergeTwoLists(&s, &q);
	SList s1 = s;
	printfSList(&s1);
	printf("\n");
	printSList(&s);
	//SListPushFront(&s, 0);
	//SListPushFront(&s, 2);
	//SListPushFront(&s, 2);
	//SListPushFront(&s, 2);
	//SListPushFront(&s, 2);
	//SListPushFront(&s, 2);
	//printSList(&s);
	//SListPopBack(&s);
	//printSList(&s);
	//SListPopFront(&s);
	//printSList(&s);
	//SListInsert(&s, BuyNewRoom(9), 1);
	//printSList(&s);
	//SListRemoveAll(&s, 2);
	//printSList(&s);
	//SListDestory(&s);
	//printSList(&s);
	return 0;
}