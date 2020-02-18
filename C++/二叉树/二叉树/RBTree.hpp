#define _CRT_SECURE_NO_WARNINGS
#pragma once 

#include<iostream>
using namespace std;

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

	bool Insert(const V& val)
	{
		//���Ƿ�Ϊ��
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(val, BLACK);
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
				if (val < pCur->_val)
					pCur = pCur->_pLeft;
				else if (val > pCur->_val)
					pCur = pCur->_pRight;
				else
					return false;
			}
			//�����½��
			pCur = new Node(val);
			if (val < pParent->_val)
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
		return true;
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		//����
		if (nullptr == pRoot)
			return true;
		//count��־�Ӹ��ڵ㵽Ҷ�ӽ���ɫ������
		size_t BlackCount = GetBlackCount(pRoot);
		size_t k = 0; //ͳ��������ɫ������
		return _IsValidRBTree(pRoot, k, BlackCount);
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
private:
	Node* _pHead;
};

void Test2()
{
	RBTree<int> t;
	int arr[] = { 7, 6, 11, 13, 12, 5, 8, 14, 10 };
	for (auto e : arr)
		t.Insert(e);
	t.InOrder();
	cout << endl;
	cout << t.GetLeft()->_val << " " << t.GetRight()->_val << endl;
	cout << t.IsValidRBTree() << endl;
}