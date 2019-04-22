#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

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