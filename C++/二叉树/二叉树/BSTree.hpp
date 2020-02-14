#define _CRT_SECURE_NO_WARNNINGS 1
#pragma once
#include<iostream>
using namespace std;


template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	:_data(data)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	{}

	T _data;
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
};

//Find Insert
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	Node* Find(const T& data) const
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		//空树
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		//按照二叉搜索树性质找当前接结点的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//进行插入
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}

	//删除结点
	/*1.叶子结点---直接删除
	  2.只有左孩子||只有右孩子（叶子节点可以合并于此）---直接删除
	  3.左右孩子都村在---找一个替代节点（该结点的左子树中最大或者右子树中最小）
	*/
	bool Delete(const T& data)
	{
		//空树，直接返回
		if (_pRoot == nullptr)
			return false;
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		//找待删除结点pCur
		while (pCur)
		{
			if (data == pCur->_data)
				break;
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		//pCur只有右孩子
		if (nullptr == pCur->_pLeft)
		{
			//根节点
			if (pCur == _pRoot)
				_pRoot = pCur->_pRight;

			//待删除结点在父节点的左边还是右边
			else
			{
				if (pParent->_pLeft == pCur)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight) //pCur只有左孩子
		{
			if (pCur == _pRoot)
				_pRoot = pCur->_pLeft;
			else
			{
				if (pParent->_pLeft == pCur)
					pParent->_pLeft = pCur->_pLeft;
				else
					pParent->_pRight = pCur->_pLeft;
			}
		}
		else     //左右孩子都有
		{
			//找右边最左边的结点进行替换
			Node* pRSwap = pCur->_pRight;
			pParent = pCur;

			while (pRSwap->_pLeft)
			{
				pParent = pRSwap;
				pRSwap = pRSwap->_pLeft;
			}
			pCur->_data = pRSwap->_data;
			if (pRSwap == pParent->_pLeft)
				pParent->_pLeft = pRSwap->_pRight;
			else
				pParent->_pRight = pRSwap->_pRight;

			pCur = pRSwap;
		}
		delete pCur;
		return true;
	}

	Node* LeftMost() const
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pLeft)
			pCur = pCur->_pLeft;
		return pCur;
	}

	Node* RightMost() const
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node* pCur = _pRoot;
		while (pCur->_pRight)
			pCur = pCur->_pRight;
		return pCur;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(Node* _pRoot)
	{
		if (_pRoot)
		{
			_InOrder(_pRoot->_pLeft);
			cout << _pRoot->_data << " ";
			_InOrder(_pRoot->_pRight);
		}
	}

	void _Destroy(Node*& _pRoot)
	{
		if (_pRoot)
		{
			_Destroy(_pRoot->_pLeft);
			_Destroy(_pRoot->_pRight);
			delete _pRoot;
		}
	}
private:
	Node* _pRoot;
};


void Test()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> tree;
	for (auto e : array)
		tree.Insert(e);

	cout << tree.LeftMost()->_data << endl;
	cout << tree.RightMost()->_data << endl;
	if (BSTNode<int>* p = tree.Find(2))
	{
		cout << "2 is in tree" << endl;
		cout << p->_data << endl;
	}
	if (tree.Find(12))
		cout << "12 is in tree" << endl;
	else
		cout << "12 is not in tree" << endl;
	tree.InOrder();
	tree.Delete(8);
	tree.InOrder();
	cout << endl;
	tree.Delete(5);
	tree.InOrder();
	cout << endl;
}