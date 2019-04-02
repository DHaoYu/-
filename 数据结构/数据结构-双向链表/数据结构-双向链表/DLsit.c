#define _CRT_SECURE_NO_WARNNINGS 1
#include"DList.h"

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

void DListInit(Node **pHead)
{
	*pHead = (Node*)malloc(sizeof(Node));
	(*pHead)->pNext = *pHead;
	(*pHead)->pPer = *pHead;
	(*pHead)->data = 0;
}

Node* BuyNewNode(Typedata data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	return pNewNode;
}

void DLsitPushBack(Node *pHead,Typedata data)
{
	Node * pNewNode = BuyNewNode(data);
	assert(pHead);
		pNewNode->pPer = pHead->pPer;
		pNewNode->pNext = pHead;
		pHead->pPer->pNext = pNewNode;
		pHead->pPer = pNewNode;
}

void DLsitPushFront(Node *pHead, Typedata data)
{
	Node *pNewNode = BuyNewNode(data);
	pNewNode->pPer = pHead;
	pNewNode->pNext = pHead->pNext;
	pHead->pNext = pNewNode;
	pNewNode->pNext->pPer = pNewNode;
}

void DLsitPopBack(Node *pHead)
{
	Node *ptr = pHead->pPer;
	pHead->pPer->pPer->pNext = pHead;
	pHead->pPer = pHead->pPer->pPer;
	//pHead->pPer->pNext = NULL;
	free(ptr);
}

void DListPopFront(Node *pHead)
{
	Node *ptr = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	pHead->pNext->pPer = pHead;
	free(ptr);
	ptr = NULL;
}

Node* DListFind(Node* pHead,Typedata data)
{
	Node *ptr = pHead->pNext;
	if (ptr == NULL)
		return NULL;
	while (ptr != pHead)
	{
		if (ptr->data == data)
		{
			return ptr;
		}
		else
			ptr = ptr->pNext;
	}
	return NULL;
}

void DListInsertBefore(Node *pos, Typedata data)
{
	Node*pNewNode = BuyNewNode(data);
	pNewNode->pNext = pos;
	pNewNode->pPer = pos->pPer;
	pos->pPer->pNext = pNewNode;
	pos->pPer = pNewNode;
}

void DListInsertAfter(Node *pos, Typedata data)
{
	Node*pNewNode = BuyNewNode(data);
	pNewNode->pNext = pos->pNext;
	pNewNode->pPer = pos;
	pos->pNext->pPer = pNewNode;
	pos->pNext = pNewNode;
}

void DListDel(Node *pos)
{
	Node *ptr = pos;
	pos->pPer->pNext = pos->pNext;
	pos->pNext->pPer = pos->pPer;
	free(ptr);
}

//void DListDelAll(Node *pos)
//{
//	Node* ptr1 = pos;
//	if (pos == NULL)
//		return 0;
//	else
//		DListDel(ptr1);
//		return DListDelAll(pos);
//}

void DListDelAll(Node *pHead, Typedata data)
{
	assert(pHead);
	Node *ptr = pHead->pNext;
	while (ptr->pNext != pHead)
	{
		if (ptr->data == data)
		{
			Node *ptr1 = ptr;
			ptr->pPer->pNext = ptr->pNext;
			ptr->pNext->pPer = ptr->pPer;
			ptr = ptr->pNext;
			free(ptr1);
		}
		else
			ptr = ptr->pNext;
	}
}
void DListDestoryHead(Node **pHead)
{
	(*pHead)->pNext = *pHead;
	(*pHead)->pPer = *pHead;
	free(*pHead);
	*pHead = NULL;
}

int DListSize(Node *pHead)
{
	int count = 0;
	Node *ptr = pHead->pNext;
	while (ptr != pHead)
	{
		count++;
	}
	return count;
}

Node* DListFirst(Node *pHead)
{
	return pHead->pNext;
}

Node* DListSecond(Node *pHead)
{
	return pHead->pNext->pNext;
}

Node* DListLast(Node *pHead)
{
	return pHead->pPer;
}

void DListDestory(Node *pHead)
{
	while (pHead->pNext !=pHead)
	{
		pHead = pHead->pNext;
		DListPopFront(pHead);
	}
	DListDestoryHead(&pHead);
	printf("双向链表已销毁\n");
}


void DLsitPrint(Node *pHead)
{
	assert(pHead);
	Node *ptr=pHead;
	if (ptr->pNext == NULL)
	{
		return;
	}
	else
	{
		while (ptr->pNext != pHead)
		{
			printf("%d--->", ptr->data);
			ptr = ptr->pNext;
		}
		printf("......\n");
	}
}