#include"SListNew.h"
#include<assert.h>
#include<stdlib.h>


Node * BuyNewNode(TypeData data)//申请节点
{
	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->Next = NULL;
	return ptr;
}
void InitSList(PSList ps)//链表初始化
{
	assert(ps);
	ps->pHead = 0;
	ps->pHead->Next = NULL;
}
void SListPushFront(PSList ps, TypeData data)//头插
{
	Node *ptr = BuyNewNode(data);

}
void SListPushBack(PSList ps, TypeData data);//尾插

void SListInsert(PSList ps, int pos, TypeData data);//任意位置插入

void SListInsertAfter(PSList ps, TypeData data);//在某一元素后面插入

