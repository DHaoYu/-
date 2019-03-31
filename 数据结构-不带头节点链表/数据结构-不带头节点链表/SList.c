#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

void SListInit(SList *pl)
{
	assert(pl);
	pl->pHead = NULL;
}

Node* BuyNewRoom(SDataType data)
{
	Node * pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	return pNewNode;
}

void SListPushBack(SList *pl,SDataType data)
{
	Node* pNewNode = BuyNewRoom(data);
	if (pl->pHead==NULL)
	{
		pl->pHead = pNewNode;
	}
	else
	{
		Node *ptr = pl->pHead;
		while (ptr->pNext)
		{
			ptr = ptr->pNext;
		}
		ptr->pNext = pNewNode;
		pNewNode->pNext = NULL;
	}
}

void SListPushFront(SList *pl, SDataType data)
{
	Node *pNewNode = BuyNewRoom(data);
	pNewNode->pNext = pl->pHead;
	pl->pHead = pNewNode;
}

void SListPopBack(SList *pl)
{
	if (pl->pHead == NULL)
		return;
	else if (pl->pHead->pNext == NULL)
	{
		free(pl->pHead);
		return;
	}
	else
	{
		Node * ptr = pl->pHead;
		while (ptr->pNext->pNext)
		{
			ptr = ptr->pNext;
		}
		free(ptr->pNext);
		ptr->pNext = NULL;
	}
}

void SListPopFront(SList *pl)
{
	Node *ptr = pl->pHead;
	pl->pHead = pl->pHead->pNext;
	free(ptr);
}

void SListInsert(SList *pl, Node *pos, SDataType data)
{
	Node* ptr1 = pl->pHead;
	Node* ptr2 = pl->pHead->pNext;
	while (ptr1->data != data)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->pNext;
	}
	ptr1->pNext = pos;
	pos->pNext = ptr2;
}


void SListDestory(SList *pl)
{
	Node* ptr = pl->pHead;
	while (pl->pHead)
	{
		pl->pHead = pl->pHead->pNext;
		free(ptr);
		ptr = pl->pHead;
	}
	printf("Á´±íÒÑÏú»Ù\n");
}

int printfSList(SList *pl)
{
	Node*ptr = pl->pHead;
	Node*ptr2 = pl->pHead;
	if (pl->pHead == NULL)
		return 0;
	else
	{
		//ptr = ptr->pNext;
		return (printfSList((&ptr->pNext)),printf("%d--->", ptr->data));
	}
}
	

void printSList(SList *pl)
{
	Node*ptr = pl->pHead;
	while (ptr)
	{
		printf("%d--->", ptr->data);
		ptr = ptr->pNext;
	}
	printf("NULL\n");
}

//
//Node * mergeTwoLists(SList* l1, SList* l2)
//{
//	Node * p1 = l1->pHead;
//	Node * p2 = l2->pHead;
//	 Node  pNew=(SList)malloc(sizeof(Node));
//	//Node  pNew;
//	Node * ptr = &pNew;
//	if (l1 == NULL || l2 == NULL && l1 == NULL)
//		return l2;
//	else if (l2 == NULL || l1 == NULL && l2 == NULL)
//		return l1;
//	else
//	{
//		while (p1 && p2)
//		{
//			if (p1->data <= p2->data)
//			{
//				ptr = p1;
//				p1 = p1->pNext;
//			}
//			else
//			{
//				ptr = p2;
//				p2 = p2->pNext;
//			}
//			ptr = ptr->pNext;
//		}
//		if (p1 == NULL)
//			ptr = p2;
//		else
//			ptr = p1;
//	}
//	return &pNew;
//}


void Del(Node* pl)
{
		Node *pSlow = pl;
		Node *pFast = pl;
		//Node *pSlowPre = pSlow;
		if (NULL == pl || NULL == pl ->pNext )
			return pl;
		while (pFast->pNext)
		{
			pFast = pFast->pNext;
			if (pSlow->pNext->data == pFast->pNext ->data)
			{
				pSlow->pNext  = pFast->pNext ->pNext;
				pFast = pFast->pNext->pNext;
			}
			else
			{
				pSlow = pSlow->pNext;
			}
		}
		return;
}