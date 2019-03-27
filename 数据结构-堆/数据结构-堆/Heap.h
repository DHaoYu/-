#define _CRT_SECURE_NO_WARNNINGS 


typedef int HTypeData;

typedef struct Heap
{
	HTypeData *array;
	int size;
	int capacity;
}Heap, *pHeap;


void CreatHeap(pHeap h);//�ѵĴ���

void AdjustDownHeap(pHeap h, int size);
void AdjustUpHeap(pHeap h, int size);
void Swap(HTypeData *parent, HTypeData *child);

void DestoryHeap(pHeap p);//���ٶ�

void InsertHeap(pHeap h,HTypeData data);//�ѵĲ���
void CheckHeapFull(pHeap h);//�����Ƿ���

void EraseHeap(pHeap h);//�Ѷ�Ԫ�����

HTypeData TopHeap(Heap* hp);//��ȡ�Ѷ�Ԫ��
int SizeHeap(Heap* hp);//��ȡ�ѵ�Ԫ�ظ���
int EmptyHeap(Heap* hp);//�ж϶��Ƿ�Ϊ��

void HeapSrot(Heap* hp);//������

void PrintHeap(pHeap p);//��ӡ��