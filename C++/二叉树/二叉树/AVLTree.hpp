#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<utility>

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>& data)
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(data)
	, _bf(0)
	{}

	AVLTreeNode<K, V>* _pLeft;
	AVLTreeNode<K, V>* _pRight;
	AVLTreeNode<K, V>* _pParent;
	pair<K, V> _data;
	int _bf; //结点的平衡因子
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const pair<K, V>& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}

		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data.first < pCur->_data.first)
				pCur = pCur->_pLeft;
			else if (data.first > pCur->_data.first)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//插入
		pCur = new Node(data);
		if (data.first < pParent->_data.first)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		pCur->_pParent = pParent;

		//更新平衡因子,使AVL树平衡
		while (pParent)
		{
			if (pParent->_pLeft == pCur)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (0 == pParent->_bf)
				break;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{//向上走一步
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				// pParent的平衡因子==+-2 时，需要进行旋转并将其平衡因子值修改
				if (2 == pParent->_bf)
				{
					if (pCur->_bf == 1)
						RotateL(pParent); //左单旋
					else
						RotateRL(pParent); //右左双旋
				}
				else //-2
				{
					if (pCur->_bf == -1) //右单旋
						RotateR(pParent);
					else
						RotateLR(pParent);//左右双旋
				}
				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_pRoot);
	}
private:
	//右单旋
	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		//将pSubL向上提 更改相关指针指向
		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		//pPParent 为空，pParent为根节点
		if (nullptr == pPParent)
			_pRoot = pSubL;
		else
		{
			//pParent 可能为pPParent的左孩子 或者 右孩子
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
		//更新平衡因子
		pSubL->_bf = pParent->_bf = 0;
	}

	//左单旋
	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		pSubR->_pLeft = pParent;
		if (pSubRL)
			pSubRL->_pParent = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;
		if (nullptr == pPParent)
			_pRoot = pSubR;
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
		//更新平衡因子
		pSubR->_bf = pParent->_bf = 0;
	}

	void RotateRL(Node* pParent)
	{
		RotateR(pParent->_pRight);
		RotateL(pParent);
	}

	void RotateLR(Node* pParent)
	{
		RotateL(pParent->_pLeft);
		RotateR(pParent);
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data.first <<" ";
			_InOrder(pRoot->_pRight);
		}
	}

	size_t _Height(Node* pRoot)
	{
		if (nullptr == pRoot)
			return 0;

		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalanceTree(Node* pRoot)
	{
		if (nullptr == pRoot)
			return true;
		size_t leftHeight = _Height(pRoot->_pLeft);
		size_t rightHeight = _Height(pRoot->_pRight);
		int bf = rightHeight - leftHeight;
		if (abs(bf) > 1 && bf != pRoot->_bf)
			return false;

		return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot->_pRight);
	}
private:
	Node* _pRoot;
};

void Test1()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1, t2;
	for (auto e : array)
		t1.Insert(make_pair(e,e));
	for (auto e : arr)
		t2.Insert(make_pair(e,e));
	t2.InOrder();
	cout << t1.IsBalanceTree() << " " << t2.IsBalanceTree();
}