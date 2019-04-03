//不带头节点单链表
typedef int TypeData;

typedef struct SNode
{
	TypeData data;
	TypeData * Next;
}Node;

typedef struct SList
{
	Node *pHead;
}SList,*PSList;

void InitSList(PSList ps);//链表初始化

void SListPushFront(PSList ps,TypeData data);//头插

void SListPushBack(PSList ps, TypeData data);//尾插

void SListInsert(PSList ps, int pos, TypeData data);//任意位置插入

void SListInsertAfter(PSList ps, TypeData data);//在某一元素后面插入



 