
typedef int Typedata;

typedef struct DoubleList
{
	Typedata data;
	struct DoubleList * pNext;
	struct DoubleList * pPer;
}Node;



void DListInit(Node **pHead);

Node* BuyNewNode(Typedata data);

void DLsitPushBack(Node *pHead, Typedata data);

void DLsitPushFront(Node *pHead, Typedata data);

void DLsitPopBack(Node *pHead);

void DListPopFront(Node *pHead);

Node* DListFind(Node* pHead, Typedata data);

void DListInsertBefore(Node *pos, Typedata data);

void DListInsertAfter(Node *pos, Typedata data);

void DListDel(Node *pos);

void DListDelAll(Node *pHead, Typedata data);

int DListSize(Node *pHead);

Node* DListFirst(Node *pHead);

Node* DListSecond(Node *pHead);

Node* DListLast(Node *pHead);

void DListDestory(Node *pHead);

void DLsitPrint(Node *pHead);