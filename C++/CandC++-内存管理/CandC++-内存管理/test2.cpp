#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

//new :申请空间--->构造对象
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
//---------------黑人问号？？？
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
//定位new：在已存在空间上执行构造函数
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
	Test* pt = (Test*)malloc(sizeof(Test));//申请一个Test类型的空间，因为构造函数没有调用

	//new(pt) Test;errot 因为Test类型对象中有参数，所以在定位new时需要传参
	//new(pt)Test;
	//用法new(空间地址)数据类型(初始化值)
	new(pt) Test(10);//定位new在申请空间之后需要用相应的delete进行销毁
	delete pt;

	int array[10] = { 0 };
	new(array + 3) int(10);
//	delete[10] array;会崩溃--->黑人问号？？？是不是数组空间无法进行释放
	return 0;
}
#endif

#if 0
//malloc 申请空间在堆上   new 在自由存储区--默认在堆上
//设计一个类，该类只能在堆上创建对象
//可知静态成员变量实在堆上创建空间的
class HeapOnly
{
public:
	static HeapOnly* GetObject()//静态的方法不需要对象进行调用
	{
		return new HeapOnly();//在类内访问构造函数申请堆上空间
	}
	//C++98 中实现方法
//private:
	//HeapOnly(const HeapOnly&);//为了防止拷贝构造函数在栈上创建对象

	//C++11中的实现方法
	//告知编译器：删除拷贝构造函数
	HeapOnly(const HeapOnly&) = delete;

private:
	HeapOnly()
	{}
};


int main()
{
	//HeapOnly o; error 将构造函数声明为私有成员，在类外将无法进行调用
	HeapOnly* hp = HeapOnly::GetObject();//需要定义为静态成员才能访问

	return 0;
}
#endif

#if 0
//设计一个类，该类只在栈上创建对象，同HeapOnly类似
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
	StackOnly::GetObject();//可实现在栈上创建对象
	StackOnly s = StackOnly::GetObject();//运算符重载
	StackOnly s1(StackOnly::GetObject());//调用拷贝构造函数
	
	return 0;
}
#endif

#if 0
//设计一个类，该类只在栈上创建对象，同HeapOnly类似
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
	void* operator new(size_t size);//将new申请堆上空间的函数置为私有成员
};

StackOnly s1;//可以在全局作用域创建栈上对象

int main()
{
	StackOnly s;
	return 0;
}
#endif