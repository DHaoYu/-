#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<mutex> 

//仿函数
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
//采用引用计数的方式 --> 可以实现资源的共享
//不是线程安全的,可以加锁解决引用计数的线程安全问题，但是不能解决对象中的内容线程安全的
namespace smart_ptr
{
	template<class T, class DF = DFDel<T>>  //第二个参数使用仿函数
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

		//在和其他对象共享时，需要将自身对象的引用计数进行修改
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();//在判断的过程中也将引用计数进行了--操作
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
				//delete _ptr; 为了完成其他类型的空间释放
				DF()(_ptr); // DF() 表示创建了一个无名对象，在使用无名对象调用()重载函数
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
		std::mutex* _pMutex; //可以进行加锁，解锁，保证其变为线程安全的
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
		//一段连续空间的话，可以直接使用vector来管理空间
		shared_ptr<FILE, FClose> sp2(fopen("array_test.cpp", "rb"));
		shared_ptr<int, Free<int>> sp3((int*)malloc(sizeof(int)));
		//shared_ptr<int> sp;
	}
}
#include<memory>

#if 0
//存在循环引用的问题
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
	//使用只能指针管理
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
//weak_ptr 为了解决shared_ptr存在的循环引用的问题
//同样使用引用计数解决
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

	std::weak_ptr<ListNode> pre; //使用weak_Ptr 控制结构体中的指针
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