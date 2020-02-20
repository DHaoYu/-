#define _CRT_SECURE_NO_WARNINGS
#pragma once 
#include<iostream>
using namespace std;

enum Color{ RED, BLACK };

template<class V>
struct RBTreeNode
{
	RBTreeNode(const V& val = V(), Color color = RED)
	: _val(val)
	, _color(color)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	{}
	RBTreeNode<V>* _pLeft;
	RBTreeNode<V>* _pRight;
	RBTreeNode<V>* _pParent;
	V _val;
	Color _color;
};

//�����˽��ĵ�������
template<class V>
class RBTreeIterator
{
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V> Self;
public:
	RBTreeIterator(Node* pNode = nullptr)
		:_pNode(pNode)
	{}

	V& operator*()
	{
		return _pNode->_val;
	}

	V* operator->()
	{
		return &(operator*());
	}
	//�ƶ�
	Self operator++()
	{
		Increament();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	Self operator--()
	{
		Decreament();
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decreament();
		return temp;
	}
	//�Ƚ�
	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}

	bool operator==(const Self& s)const
	{
		return _pNode == s._pNode;
	}

	void Increament()
	{
		//��ǰ�����������Ƿ���� �������������
		if (_pNode->_pRight)
		{
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft)
				_pNode = _pNode->_pLeft;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (_pNode == pParent->_pRight)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			//һ���������---Node�ڸ��ڵ�λ�� �������û��������
			if (_pNode->_pRight != pParent)
			_pNode = pParent;
		}
	}
	void Decreament()
	{
		//pNode ��end��λ�ü�head��λ��
		if (_pNode == _pNode->_pParent->_pParent && _pNode->_color == RED)
		{
			_pNode = _pNode->_pRight;
		}
		//�����������Ҳ�
		if (_pNode->_pLeft)
		{
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight)
				_pNode = _pNode->_pRight;
		}
		else
		{
			Node* pParent = _pNode->_pParent;
			while (pParent->_pLeft == _pNode)
			{
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			_pNode = pParent;
		}
	}
private:
	Node* _pNode;
};

//KeyOfValue �ǴӼ�ֵ������ȡkey�ķº���, K��key V�Ǽ�ֵ��
template<class V, class K, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<V> Node;
public:
	typedef RBTreeIterator<V> iterator;

	iterator begin()
	{
		return iterator(_pHead->_pLeft);
	}

	iterator end()
	{
		return iterator(_pHead);
	}
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
		_size = 0;
	}

	~RBTree()
	{
		Clear();
		delete _pHead;
		_pHead = nullptr;
	}

	pair<iterator, bool> Insert(const V& val)
	{
		Node* pNewNode = nullptr;
		//���Ƿ�Ϊ��
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pNewNode = pRoot = new Node(val, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else
		{
			//���ն��������������Ҵ�����λ��
			Node* pCur = pRoot;
			Node* pParent = _pHead;
			while (pCur)
			{
				pParent = pCur;
				if (KeyOfValue()(val) < KeyOfValue()(pCur->_val))
					pCur = pCur->_pLeft;
				else if (KeyOfValue()(val) > KeyOfValue()(pCur->_val))
					pCur = pCur->_pRight;
				else
					return make_pair(iterator(pCur), false);
			}
			//�����½��
			pNewNode = pCur = new Node(val);
			if (KeyOfValue()(val) < KeyOfValue()(pParent->_val))
				pParent->_pLeft = pCur;
			else
				pParent->_pRight = pCur;
			pCur->_pParent = pParent;
			//������ɫ�������һ��һ��Υ�����������
			Node* pPParent = pParent->_pParent;
			Node* pUncle = nullptr;
			if (pPParent->_pLeft == pParent)
				pUncle = pPParent->_pRight;
			else
				pUncle = pPParent->_pLeft;

			while (pParent->_color != BLACK && pParent != _pHead)
			{
				//������Ϊ��ɫ
				if (pUncle && pUncle->_color == RED)
				{
					pUncle->_color = BLACK;
					pParent->_color = BLACK;
					pPParent->_color = RED;

					pCur = pPParent;
					pParent = pCur->_pParent;
					pPParent = pParent->_pParent;
					pUncle = pPParent->_pRight;
				}
				else //������Ϊ��ɫ���߲�����
				{
					//���׽�����游������ڵ�
					if (pParent == pPParent->_pLeft)
					{
						//�������Ǹ��׽����ҽڵ� ��Ҫ����תһ��
						if (pParent->_pRight == pCur)
							RotateL(pParent);
						//pCurΪ��ڵ�
						pParent = pCur; //��ת��֮�󽻻����׶��ӽ��ָ��
						pCur = pCur->_pParent;
						pParent->_color = BLACK;
						pPParent->_color = RED;
						RotateR(pParent->_pParent);
					}
					else//���׽��Ϊ�游�����ҽڵ�
					{
						//pCurΪ��ڵ�
						if (pParent->_pLeft == pCur)
							RotateR(pParent);
						//pCurΪ�ҽڵ�
						pParent = pCur;
						pCur = pCur->_pParent;
						pParent->_color = BLACK;
						pPParent->_color = RED;
						RotateL(pParent->_pParent);
					}
				}
			}
		}
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		pRoot->_color = BLACK;
		++_size;
		return make_pair(iterator(pNewNode), true);
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		//����
		if (nullptr == pRoot)
			return true;
		if (pRoot->_color == RED)
			return false;
		//count��־�Ӹ��ڵ㵽Ҷ�ӽ���ɫ������
		size_t BlackCount = GetBlackCount(pRoot);
		size_t k = 0; //ͳ��������ɫ������
		return _IsValidRBTree(pRoot, k, BlackCount);
	}

	//map set��find����
	iterator Find(const K& key)
	{
		Node* pCur = GetRoot();
		while (pCur)
		{
			if (KeyOfValue()(pCur->_val) == key)
				return iterator(pCur);
			else if (key < KeyOfValue()(pCur->_val))
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return iterator(_pHead); //û�ҵ�
	}

	void InOrder()
	{
		Node* pRoot = GetRoot();
		_InOrder(pRoot);
	}

	Node* GetLeft()
	{
		return LeftMost();
	}

	Node* GetRight()
	{
		return RightMost();
	}

	bool Empty()const
	{
		return !GetRoot();
	}

	size_t Size() const
	{
		return _size;
	}

	void Swap(RBTree<V, K, KeyOfValue>& t)
	{
		swap(_pHead->_pParent, t._pHead->_pParent);
	}

	void Clear()
	{
		_Destroy(_pHead->_pParent);
		_size = 0;
	}
private:
	bool _IsValidRBTree(Node* pCur, size_t k, size_t BlackCount)
	{
		if (nullptr == pCur)
			return true;

		//ͳ�ƺ�ɫ������
		if (BLACK == pCur->_color)
			++k;

		//��鵱ǰ�������˫���Ƿ�Ϊ��ɫ
		Node* pParent = pCur->_pParent;
		if (pParent->_color == RED && pCur->_color == RED)
			return false;
		//����ɫ����Ƿ���ͬ
		if (nullptr == pCur->_pLeft && nullptr == pCur->_pRight)
		if (k != BlackCount)
			return false;

		return _IsValidRBTree(pCur->_pLeft, k, BlackCount) &&
			_IsValidRBTree(pCur->_pRight, k, BlackCount);
	}

	size_t GetBlackCount(Node* pCur)
	{
		size_t count = 0;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				++count;
			pCur = pCur->_pLeft;
		}
		return count;
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_val << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		//��pSubL������ �������ָ��ָ��
		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//����pParentΪ���ڵ�
		if (_pHead == pPParent)
			_pHead->_pParent = pSubL;
		else
		{
			//pParent ����ΪpPParent������ ���� �Һ���
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		//��pSubR ����
		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		pParent->_pParent = pSubR;
		if (pPParent == _pHead)
			_pHead->_pParent = pSubR;
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
	}

	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}
	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}

	void _Destroy(Node*& pRoot)
	{
		if (pRoot == nullptr)
			return;
		_Destroy(pRoot->_pLeft);
		_Destroy(pRoot->_pRight);
		delete pRoot;
	}
private:
	Node* _pHead;
	size_t _size;
};

#if 0
void TestIt()
{
	RBTree<int> t;
	int arr[] = { 7, 6, 11, 13, 12, 5, 8, 14, 10 };
	for (auto e : arr)
		t.Insert(e);
	t.InOrder();
	RBTree<int>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it++ << " "; 
	}
}
#endif