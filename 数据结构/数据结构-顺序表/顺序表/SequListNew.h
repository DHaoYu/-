
typedef int TypeData;

typedef struct SqList
{
	TypeData *elem;//数组元素
	int Size;//数组大小
	int Length;//数组长度
}SqList,*PSqList;//结构体变量和结构体指针变量

void CheckSqList();//检查顺序表是否为满

void InitSqList(PSqList ps);//顺序表初始化

void SqListPushFront(PSqList ps, TypeData data);//顺序表头插

void SqListPushBack(PSqList ps,TypeData data);//顺序表尾插

void SqListPopFront(PSqList ps);//顺序表头删

void SqListPopBack(PSqList ps);//顺序表尾删

void SqListDelete(PSqList ps,int pos);//任意位置删除

void SqListInsert(PSqList ps, int pos, TypeData data);//任意位置插入

void SqListPrint(PSqList ps);//打印验证