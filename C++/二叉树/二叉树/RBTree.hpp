#define _CRT_SECURE_NO_WARNINGS
#pragma once 

enum Color{RED, BLACK};

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

template<class V>
class RBTree
{
	typedef RBTreeNode<V> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const v& val)
	{
		//树是否为空
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
			pRoot->_pParent = _pHead;
		}
		else
		{
			//按照二叉搜索树性质找待插入位置

			//插入新结点

			//两个红色结点连在一起一定违反红黑树性质
		}

		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		pRoot->_color = BLACK;
		return true;
	}
private:
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
private:
	Node* _pHead;
};