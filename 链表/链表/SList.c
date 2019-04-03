
#define _CRT_SECURE_NO_WARNNINGS 1
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include"SList.h"

void SListInit(SList* pl)//�����ʼ��
{
	assert(pl);
	pl->_pHead = (Node*)malloc(sizeof(Node));
	pl->_pHead->_pNext = NULL;
}

Node* BuySListRoom(SDataType data)//����ռ�
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
		assert(0);
	pNewNode->_data = data;
	return pNewNode;
}

void SListPushBack(SList* pl, SDataType data)//β��
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

// �������� 
void SListDestroy(SList* pl)
{
	while (pl->_pHead != NULL)
	{
		Node* ptr=pl->_pHead->_pNext;
		free(pl->_pHead);
		pl->_pHead = ptr;
	}
	printf("����������\n");
}
// ɾ���������һ���ڵ� 
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

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = BuySListRoom(data);
	pNewNode->_pNext = pl->_pHead->_pNext;
	pl->_pHead->_pNext = pNewNode;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	Node* ptr = pl->_pHead->_pNext;
	pl->_pHead->_pNext = pl->_pHead->_pNext->_pNext;
	free(ptr);
}

// ������posλ�ú����ֵΪdata�Ľڵ� 
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

// ɾ��������ֵΪdata�Ľڵ� 
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

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
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

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	int count = 0;
	Node* ptr = pl->_pHead;
	while (ptr->_pNext)
	{
		count++;
	}
	printf("������Ϊ��\n",count);
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	if (pl->_pHead == NULL)
	{
		return -1;
	}
	else
		return 1;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	return pl->_pHead->_pNext;
}

// ��ȡ����ĵڶ����ڵ� 
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