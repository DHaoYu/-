#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

//new :����ռ�--->�������
using namespace std;

#if 0 
struct ListNode
{
	ListNode* _pNext;
	ListNode* _pPrev;
	int _data;

	ListNode(int data = 0)
		:_pNext(nullptr)
		, _pPrev(nullptr)
		, _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "ListNode(int):" << this << endl;
	}

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_pNext = _head;
		_head->_pPrev = _head;
	}
	
	~List()
	{
		ListNode* cur = _head->_pNext;
		while (cur != _head)
		{
			ListNode* next = cur->_pNext;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

int main()
{   
	List L;
	return 0;
}
#endif

#if 0
//---------------�����ʺţ�����
void* operator new(size_t size,char* fileName, char* funcName, int lineNo)
{
	cout << fileName << "-" << funcName << "-" << lineNo << ":" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCTION__, __LINE__)

int main()
{
	int* p = new int;
	delete p;

	return 0;
}
#endif


#if 0
//��λnew�����Ѵ��ڿռ���ִ�й��캯��
class Test
{
public:
	Test(int data)
	:_data(data)
	{
		cout << "Tes(int):" << this << endl;
	}

	Test(const Test& t)
		:_data(t._data)
	{
		cout << "Test(const Test&):" << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));//����һ��Test���͵Ŀռ䣬��Ϊ���캯��û�е���

	//new(pt) Test;errot ��ΪTest���Ͷ������в����������ڶ�λnewʱ��Ҫ����
	//new(pt)Test;
	//�÷�new(�ռ��ַ)��������(��ʼ��ֵ)
	new(pt) Test(10);//��λnew������ռ�֮����Ҫ����Ӧ��delete��������
	delete pt;

	int array[10] = { 0 };
	new(array + 3) int(10);
//	delete[10] array;�����--->�����ʺţ������ǲ�������ռ��޷������ͷ�
	return 0;
}
#endif

#if 0
//malloc ����ռ��ڶ���   new �����ɴ洢��--Ĭ���ڶ���
//���һ���࣬����ֻ���ڶ��ϴ�������
//��֪��̬��Ա����ʵ�ڶ��ϴ����ռ��
class HeapOnly
{
public:
	static HeapOnly* GetObject()//��̬�ķ�������Ҫ������е���
	{
		return new HeapOnly();//�����ڷ��ʹ��캯��������Ͽռ�
	}
	//C++98 ��ʵ�ַ���
//private:
	//HeapOnly(const HeapOnly&);//Ϊ�˷�ֹ�������캯����ջ�ϴ�������

	//C++11�е�ʵ�ַ���
	//��֪��������ɾ���������캯��
	HeapOnly(const HeapOnly&) = delete;

private:
	HeapOnly()
	{}
};


int main()
{
	//HeapOnly o; error �����캯������Ϊ˽�г�Ա�������⽫�޷����е���
	HeapOnly* hp = HeapOnly::GetObject();//��Ҫ����Ϊ��̬��Ա���ܷ���

	return 0;
}
#endif

#if 0
//���һ���࣬����ֻ��ջ�ϴ�������ͬHeapOnly����
class StackOnly
{
public:
	static StackOnly GetObject()
	{
		return StackOnly();
	}

	StackOnly(const StackOnly& s)
	{
		cout << "StackOnly(cosnt StackOnly&)" << endl;
	}

private:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}
};

int main()
{
	StackOnly::GetObject();//��ʵ����ջ�ϴ�������
	StackOnly s = StackOnly::GetObject();//���������
	StackOnly s1(StackOnly::GetObject());//���ÿ������캯��
	
	return 0;
}
#endif

#if 0
//���һ���࣬����ֻ��ջ�ϴ�������ͬHeapOnly����
class StackOnly
{
public:
	StackOnly()
	{
		cout << "StackOnly()" << endl;
	}

	//static StackOnly GetObject()
	//{
	//	return StackOnly();
	//}

	StackOnly(const StackOnly& s)
	{
		cout << "StackOnly(cosnt StackOnly&)" << endl;
	}

private:
	void* operator new(size_t size);//��new������Ͽռ�ĺ�����Ϊ˽�г�Ա
};

StackOnly s1;//������ȫ�������򴴽�ջ�϶���

int main()
{
	StackOnly s;
	return 0;
}
#endif