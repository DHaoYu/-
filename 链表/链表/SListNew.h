//����ͷ�ڵ㵥����
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

void InitSList(PSList ps);//�����ʼ��

void SListPushFront(PSList ps,TypeData data);//ͷ��

void SListPushBack(PSList ps, TypeData data);//β��

void SListInsert(PSList ps, int pos, TypeData data);//����λ�ò���

void SListInsertAfter(PSList ps, TypeData data);//��ĳһԪ�غ������



 