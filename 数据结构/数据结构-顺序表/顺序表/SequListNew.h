
typedef int TypeData;

typedef struct SqList
{
	TypeData *elem;//����Ԫ��
	int Size;//�����С
	int Length;//���鳤��
}SqList,*PSqList;//�ṹ������ͽṹ��ָ�����

void CheckSqList();//���˳����Ƿ�Ϊ��

void InitSqList(PSqList ps);//˳����ʼ��

void SqListPushFront(PSqList ps, TypeData data);//˳���ͷ��

void SqListPushBack(PSqList ps,TypeData data);//˳���β��

void SqListPopFront(PSqList ps);//˳���ͷɾ

void SqListPopBack(PSqList ps);//˳���βɾ

void SqListDelete(PSqList ps,int pos);//����λ��ɾ��

void SqListInsert(PSqList ps, int pos, TypeData data);//����λ�ò���

void SqListPrint(PSqList ps);//��ӡ��֤