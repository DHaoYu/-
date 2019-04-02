//#include"SequList.h"
//
//int main()
//{
//	SeqList S;
//	SeqListInit(&S);
//	printf("在顺序表中插入数据：\n");
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
//	printf("顺序表尾删:\n");
//	SeqListPopBack(&S);
//	PrintSeqList(&S);
//	printf("顺序表头删:\n");
//	SeqListPopFront(&S);
//	PrintSeqList(&S);
//	printf("任意位置插入：\n");
//	SeqListInsert(&S, 1, 9);
//	PrintSeqList(&S);
//	printf("任意位置删除:\n");
//	SeqListErase(&S, 0);
//	PrintSeqList(&S);
//	SeqListFind(&S, 9);
//	PrintSeqList(&S);
//	printf("移除顺序表中第一个值为data的元素: \n");
//	SeqListRemove(&S, 9);
//	PrintSeqList(&S);
//	printf("移除顺序表中所有值为data的元素：\n ");
//	SeqListRemoveAll(&S, 1);
//	PrintSeqList(&S);
//	SeqListSize(&S);
//	PrintSeqList(&S);
//	PrintSeqList(&S);
//	SeqListCapacity(&S);
//	SeqListEmpty(&S);
//	PrintSeqList(&S);
//	printf("第一个值为:\n");
//	SeqListFront(&S);
//	PrintSeqList(&S);
//	printf("最后一个值为:\n");
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