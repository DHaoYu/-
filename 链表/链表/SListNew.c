#include"SListNew.h"
#include<assert.h>
#include<stdlib.h>


Node * BuyNewNode(TypeData data)//����ڵ�
{
	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->Next = NULL;
	return ptr;
}
void InitSList(PSList ps)//�����ʼ��
{
	assert(ps);
	ps->pHead = 0;
	ps->pHead->Next = NULL;
}
void SListPushFront(PSList ps, TypeData data)//ͷ��
{
	Node *ptr = BuyNewNode(data);

}
void SListPushBack(PSList ps, TypeData data);//β��

void SListInsert(PSList ps, int pos, TypeData data);//����λ�ò���

void SListInsertAfter(PSList ps, TypeData data);//��ĳһԪ�غ������

