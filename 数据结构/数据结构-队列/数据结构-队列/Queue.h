#define _CRT_SECURE_NO_WARNNINGS 1

typedef int QTypeData;

typedef struct Queue
{
	QTypeData *array;
	int _size;
	int _capacity;
}*PQueue, Queue;


void QueueInit(PQueue q);//队列初始化

void CheckIsFullQueue(PQueue q);//判断队列是否为满

void PushQueue(PQueue q, QTypeData data);//入队列

void PopQueue(PQueue q);//出队列

QTypeData GetFirstQueue(PQueue q);//获取队首元素

QTypeData GetLastQueue(PQueue q);//获取队尾元素

int GetQueueSize(PQueue q);//获取队中元素个数

void DestoryQueue(PQueue q);//队列的销毁



