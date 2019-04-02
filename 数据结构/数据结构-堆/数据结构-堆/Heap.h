#define _CRT_SECURE_NO_WARNNINGS 


typedef int HTypeData;

typedef struct Heap
{
	HTypeData *array;
	int size;
	int capacity;
}Heap, *pHeap;


void CreatHeap(pHeap h);//堆的创建

void AdjustDownHeap(pHeap h, int size);
void AdjustUpHeap(pHeap h, int size);
void Swap(HTypeData *parent, HTypeData *child);

void DestoryHeap(pHeap p);//销毁堆

void InsertHeap(pHeap h,HTypeData data);//堆的插入
void CheckHeapFull(pHeap h);//检查堆是否满

void EraseHeap(pHeap h);//堆顶元素清除

HTypeData TopHeap(Heap* hp);//获取堆顶元素
int SizeHeap(Heap* hp);//获取堆的元素个数
int EmptyHeap(Heap* hp);//判断堆是否为空

void HeapSrot(Heap* hp);//堆排序

void PrintHeap(pHeap p);//打印堆