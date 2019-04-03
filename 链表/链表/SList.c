
#define _CRT_SECURE_NO_WARNNINGS 1
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include"SList.h"

void SListInit(SList* pl)//链表初始化
{
	assert(pl);
	pl->_pHead = (Node*)malloc(sizeof(Node));
	pl->_pHead->_pNext = NULL;
}

Node* BuySListRoom(SDataType data)//申请空间
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
		assert(0);
	pNewNode->_data = data;
	return pNewNode;
}

void SListPushBack(SList* pl, SDataType data)//尾插
{
	Node* pNewNode = BuySListRoom(data);
	Node* ptr=NULL;
	pNewNode->_pNext = NULL;
	if (NULL == pl->_pHead->_pNext)
	{
		pl->_pHead->_pNext = pNewNode;
	}
	else
	{
		ptr = pl->_pHead;
		while (ptr->_pNext != NULL)
		{
			ptr = ptr->_pNext;
		}
		ptr->_pNext = pNewNode;
		pNewNode->_pNext = NULL;
	}
}

// 销毁链表 
void SListDestroy(SList* pl)
{
	while (pl->_pHead != NULL)
	{
		Node* ptr=pl->_pHead->_pNext;
		free(pl->_pHead);
		pl->_pHead = ptr;
	}
	printf("链表已销毁\n");
}
// 删除链表最后一个节点 
void SListPopBack(SList* pl)
{
	Node* ptr = pl->_pHead;
	while (ptr->_pNext->_pNext)
	{
		ptr = ptr->_pNext;
	}
	free(ptr->_pNext);
	ptr->_pNext = NULL;
}

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = BuySListRoom(data);
	pNewNode->_pNext = pl->_pHead->_pNext;
	pl->_pHead->_pNext = pNewNode;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	Node* ptr = pl->_pHead->_pNext;
	pl->_pHead->_pNext = pl->_pHead->_pNext->_pNext;
	free(ptr);
}

// 在链表pos位置后插入值为data的节点 
void SListInsertAfter(SList *pl, Node* pos, SDataType data)
{
	Node* ps = pl->_pHead->_pNext;
	Node* ptr = pl->_pHead;
	while (ps->_data != pos->_data)
	{
		ptr = ps;
		ps = ps->_pNext;
	}
	ptr->_pNext = pos;
	pos->_pNext = ps->_pNext->_pNext;
}

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos)
{
	assert(pl);
	Node* ptr = pl->_pHead;
	Node* ps = pl->_pHead->_pNext;
	Node* ps1 = pl->_pHead;
	while (ptr->_pNext!=NULL)
	{
		if (ps->_data == pos->_data)
		{
			ptr->_pNext = ps->_pNext;
			//free(ps1);
			ps = ptr;
		}
		ptr = ps;
		ps = ps->_pNext;
	}
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data)
{
	Node* ptr = pl->_pHead;
	while (ptr->_pNext)
	{
		if (ptr->_data = data)
		{
			return ptr;
		}
		ptr = ptr->_pNext;
	}
	return NULL;
}

// 获取链表中有效节点的个数 
int SListSize(SList* pl)
{
	int count = 0;
	Node* ptr = pl->_pHead;
	while (ptr->_pNext)
	{
		count++;
	}
	printf("结点个数为：\n",count);
	return count;
}

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	if (pl->_pHead == NULL)
	{
		return -1;
	}
	else
		return 1;
}

// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	return pl->_pHead->_pNext;
}

// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNext->_pNext;
}


//////////////////////////////////////
void printSList(SList*pl)
{
	assert(pl);
	Node* ptr = pl->_pHead;
	while (ptr->_pNext !=NULL)
	{
		ptr = ptr->_pNext;
		printf("%d--->", ptr->_data);
	}
	printf("NULL\n");
}