typedef int HTypeDate;

typedef struct Heap
{
	HTypeDate *array;
	int size;
	int capacity;
}Heap,*pHeap;

void CreatHeap(Heap *hp,int length);//创建堆
void DestoryHeap(Heap *hp);//销毁堆
void swap(Heap *hp, int parent, int child);//交换
void InsertHeap(Heap *hp,HTypeDate date);//堆插入
void DeledteTopHeap(Heap *hp);//头结点删除
void HeapAdjustDown(Heap *hp);//堆向下调整
int IsemptyHeap(Heap *hp);//判空
HTypeDate TopHeap(Heap *hp);//返回堆顶