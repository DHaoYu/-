#define _CRT_SECURE_NO_WARNNINGS 1
#include "DList.h"
int main()
{
	Node * pHead;
	DListInit(&pHead);
	DLsitPushBack(pHead, 1);
	DLsitPushBack(pHead, 2);
	DLsitPushBack(pHead, 2);
	DLsitPushBack(pHead, 2);
	DLsitPushBack(pHead, 2);
	DLsitPushBack(pHead, 3);
	DLsitPushBack(pHead, 4);
	DLsitPrint(pHead);
	DLsitPushFront(pHead, 0);
	DLsitPrint(pHead);
	DLsitPopBack(pHead);
	DLsitPrint(pHead);
	DListPopFront(pHead);
	DLsitPrint(pHead);
	DListInsertBefore(DListFind(pHead, 2), 9);
	DLsitPrint(pHead);
	DListInsertAfter(DListFind(pHead, 3), 8);
	DLsitPrint(pHead);
	DListDel(DListFind(pHead, 3));
	DLsitPrint(pHead);
	DListDelAll(pHead, 2);
	DLsitPrint(pHead);
	int DListSize(pHead);
	DListDestory(pHead);
}