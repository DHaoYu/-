#define _CRT_SECURE_NO_WARNNINGS 1

typedef int QTypeData;

typedef struct Queue
{
	QTypeData *array;
	int _size;
	int _capacity;
}*PQueue, Queue;


void QueueInit(PQueue q);//���г�ʼ��

void CheckIsFullQueue(PQueue q);//�ж϶����Ƿ�Ϊ��

void PushQueue(PQueue q, QTypeData data);//�����

void PopQueue(PQueue q);//������

QTypeData GetFirstQueue(PQueue q);//��ȡ����Ԫ��

QTypeData GetLastQueue(PQueue q);//��ȡ��βԪ��

int GetQueueSize(PQueue q);//��ȡ����Ԫ�ظ���

void DestoryQueue(PQueue q);//���е�����



