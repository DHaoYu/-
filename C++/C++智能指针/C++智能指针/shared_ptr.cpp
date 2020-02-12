#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<mutex> 

//�º���
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};
//�������ü����ķ�ʽ --> ����ʵ����Դ�Ĺ���
//�����̰߳�ȫ��,���Լ���������ü������̰߳�ȫ���⣬���ǲ��ܽ�������е������̰߳�ȫ��
namespace smart_ptr
{
	template<class T, class DF = DFDel<T>>  //�ڶ�������ʹ�÷º���
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pMutex(new std::mutex())
		{
			if (_ptr)
				_pCount = new int(1);
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(new std::mutex())
		{
			AddRefCount();
		}

		//�ں�����������ʱ����Ҫ�������������ü��������޸�
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();//���жϵĹ�����Ҳ�����ü���������--����
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				AddRefCount();
			}
			return *this;
		}

		T& operator*() const 
		{
			return *_ptr;
		}

		T* operator->() const 
		{
			return _ptr;
		}
		
		~shared_ptr()
		{
			Release();
			delete _pMutex;
		}
	private:
		void Release()
		{
			_pMutex->lock();
			if (_ptr && 0 == --(*_pCount))
			{
				//delete _ptr; Ϊ������������͵Ŀռ��ͷ�
				DF()(_ptr); // DF() ��ʾ������һ������������ʹ�������������()���غ���
				delete _pCount;
			}
			_pMutex->unlock();
		}

		void AddRefCount()
		{
			_pMutex->lock();
			if (_ptr)
				(*_pCount)++;
			_pMutex->unlock();
		}
	private:
		T* _ptr;
		int* _pCount;
		std::mutex* _pMutex; //���Խ��м�������������֤���Ϊ�̰߳�ȫ��
	};

	void TestFunc1()
	{
		shared_ptr<int> sp1(new int);
		shared_ptr<int> sp2(sp1);
		shared_ptr<int> sp3;
		shared_ptr<int> sp4(new int);
		shared_ptr<int> sp5(new int);
		sp3 = sp1;
		sp4 = sp2;
		sp1 = sp5;
	}
	void TestFunc2()
	{
		//shared_ptr<int> sp1(new int[10]); 
		//һ�������ռ�Ļ�������ֱ��ʹ��vector������ռ�
		shared_ptr<FILE, FClose> sp2(fopen("array_test.cpp", "rb"));
		shared_ptr<int, Free<int>> sp3((int*)malloc(sizeof(int)));
		//shared_ptr<int> sp;
	}
}
#include<memory>

#if 0
//����ѭ�����õ�����
struct ListNode
{
	ListNode(int data = int())
	: pre(nullptr)
	, next(nullptr)
	, _data(data)
	{
		std::cout << "ListNode():" << this << std::endl;
	}

	~ListNode()
	{
		std::cout << "~ListNode" << std::endl;
	}
	//ListNode* _pPre;
	//ListNode* _pNext;
	//ʹ��ֻ��ָ�����
	std::shared_ptr<ListNode> pre;
	std::shared_ptr<ListNode> next;

	int _data;
};

int main()
{
	std::shared_ptr<ListNode> sp1(new ListNode(10));
	std::shared_ptr<ListNode> sp2(new ListNode(20));
	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;
	
	sp1->next = sp2;
	sp2->pre = sp1;

	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;

	//std::shared_ptr<int> sp(new int);
	//*sp = 10;
	//smart_ptr::TestFunc2();
	//std::string *str = new std::string();
}
#endif


#if 0
//weak_ptr Ϊ�˽��shared_ptr���ڵ�ѭ�����õ�����
//ͬ��ʹ�����ü������
struct ListNode
{
	ListNode(int data = int())
	: _data(data)
	{
		std::cout << "ListNode():" << this << std::endl;
	}

	~ListNode()
	{
		std::cout << "~ListNode" << this << std::endl;
	}
	//ListNode* _pPre;
	//ListNode* _pNext;

	std::weak_ptr<ListNode> pre; //ʹ��weak_Ptr ���ƽṹ���е�ָ��
	std::weak_ptr<ListNode> next;

	int _data;
};
int main()
{
	std::shared_ptr<ListNode> sp1(new ListNode(10));
	std::shared_ptr<ListNode> sp2(new ListNode(20));
	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;

	sp1->next = sp2;
	sp2->pre = sp1;

	std::cout << sp1.use_count() << std::endl;
	std::cout << sp2.use_count() << std::endl;
	return 0;
}
#endif