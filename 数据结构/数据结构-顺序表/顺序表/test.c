//#include"SequList.h"
//
//int main()
//{
//	SeqList S;
//	SeqListInit(&S);
//	printf("��˳����в������ݣ�\n");
//	SeqListPushBack(&S, 1);
//	SeqListPushBack(&S, 2);
//	SeqListPushBack(&S, 3);
//	SeqListPushBack(&S, 4);
//	SeqListPushFront(&S, 0);
//	SeqListPushFront(&S, 1);
//	SeqListPushFront(&S, 2);
//	SeqListPushFront(&S, 3);
//	PrintSeqList(&S);
//	CheckSeeqList(&S);
//	printf("˳���βɾ:\n");
//	SeqListPopBack(&S);
//	PrintSeqList(&S);
//	printf("˳���ͷɾ:\n");
//	SeqListPopFront(&S);
//	PrintSeqList(&S);
//	printf("����λ�ò��룺\n");
//	SeqListInsert(&S, 1, 9);
//	PrintSeqList(&S);
//	printf("����λ��ɾ��:\n");
//	SeqListErase(&S, 0);
//	PrintSeqList(&S);
//	SeqListFind(&S, 9);
//	PrintSeqList(&S);
//	printf("�Ƴ�˳����е�һ��ֵΪdata��Ԫ��: \n");
//	SeqListRemove(&S, 9);
//	PrintSeqList(&S);
//	printf("�Ƴ�˳���������ֵΪdata��Ԫ�أ�\n ");
//	SeqListRemoveAll(&S, 1);
//	PrintSeqList(&S);
//	SeqListSize(&S);
//	PrintSeqList(&S);
//	PrintSeqList(&S);
//	SeqListCapacity(&S);
//	SeqListEmpty(&S);
//	PrintSeqList(&S);
//	printf("��һ��ֵΪ:\n");
//	SeqListFront(&S);
//	PrintSeqList(&S);
//	printf("���һ��ֵΪ:\n");
//	SeqListBack(&S);
//	PrintSeqList(&S);
//	SeqListDestroy(&S);
//	return 0;
//}
//==========================================
#include"SequListNew.h"
int main()
{
	SqList s;
	InitSqList(&s);
	SqListPushFront(&s, 0);	
	SqListPushBack(&s, 9);
	SqListPrint(&s);
	SqListPushFront(&s, 1);
	SqListPushBack(&s, 8);
	SqListPopFront(&s);
	SqListPrint(&s);
	SqListPushFront(&s, 2);
	SqListPopBack(&s);
	SqListPrint(&s);
	SqListPushFront(&s, 3);
	SqListPushFront(&s, 4);
	SqListPrint(&s);
	SqListDelete(&s, 0);
	SqListPrint(&s);
	SqListInsert(&s, 1, 9);
	SqListInsert(&s, 18, 9);
	SqListPrint(&s);
	return 0;
}