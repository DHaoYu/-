
typedef int SDataType;

typedef struct SList
{
	SDataType data;
	struct SList * pNext;
}Node;

typedef struct Node
{
	Node * pHead;
}SList;

void SListInit(SList *pl);

void SListPushBack(SList *pl,SDataType data);

void SListPushFront(SList *pl, SDataType data);

void SListPopBack(SList *pl);

void SListPopFront(SList *pl);

void SListInsert(SList *pl,Node* pos,SDataType data);

void SListRemoveAll(SList *pl,SDataType data);

void SListDestory(SList *pl);

void printSList(SList *pl);

int printfSList(SList *ptr);

Node* BuyNewRoom(SDataType data);

Node * mergeTwoLists(SList* l1, SList* l2);
void Del(SList * pl);