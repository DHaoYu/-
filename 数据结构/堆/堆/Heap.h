typedef int HTypeDate;

typedef struct Heap
{
	HTypeDate *array;
	int size;
	int capacity;
}Heap,*pHeap;

void CreatHeap(Heap *hp,int length);//������
void DestoryHeap(Heap *hp);//���ٶ�
void swap(Heap *hp, int parent, int child);//����
void InsertHeap(Heap *hp,HTypeDate date);//�Ѳ���
void DeledteTopHeap(Heap *hp);//ͷ���ɾ��
void HeapAdjustDown(Heap *hp);//�����µ���
int IsemptyHeap(Heap *hp);//�п�
HTypeDate TopHeap(Heap *hp);//���ضѶ�