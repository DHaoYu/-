#define _CRT_SECURE_NO_WARNNINGS 1
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include"SList.h"

void SListInit(SList* pl)//Á´±í³õÊ¼»¯
{
	assert(pl);
	pl->_pHead = NULL;
}

Node* BuySListRoom(SDataType data)
{
	Node* pNewNode =(Node*)malloc(sizeof(Node));
	pNewNode->_data = data;
	return pNewNode;
}

void SListPushBack(SList* pl, SDataType data)
{
	Node* pNewNode = BuySListRoom(data);
	if (NULL == pl->_pHead)
	{
		pl->_pHead->_pNext = pNewNode;
		pNewNode->_pNext = NULL;
	}
	else
	{
		while (pl->_pHead->_pNext)
		{
			pl->_pHead = pl->_pHead->_pNext;
		}
		pl->_pHead->_pNext = pNewNode;
		pNewNode = NULL;
	}
}





//////////////////////////////////////
void printSList(SList*pl)
{
	while (pl->_pHead->_pNext)
	{
		pl->_pHead = pl->_pHead->_pNext;
		printf("%d--->", pl->_pHead->_data);
	}
	printf("NULL\n");
}