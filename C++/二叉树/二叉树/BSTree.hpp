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
		//����
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		//���ն��������������ҵ�ǰ�ӽ���λ��
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
		//���в���
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		return true;
	}

	//ɾ�����
	/*1.Ҷ�ӽ��---ֱ��ɾ��
	  2.ֻ������||ֻ���Һ��ӣ�Ҷ�ӽڵ���Ժϲ��ڴˣ�---ֱ��ɾ��
	  3.���Һ��Ӷ�����---��һ������ڵ㣨�ý���������������������������С��
	*/
	bool Delete(const T& data)
	{
		//������ֱ�ӷ���
		if (_pRoot == nullptr)
			return false;
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		//�Ҵ�ɾ�����pCur
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
		//pCurֻ���Һ���
		if (nullptr == pCur->_pLeft)
		{
			//���ڵ�
			if (pCur == _pRoot)
				_pRoot = pCur->_pRight;

			//��ɾ������ڸ��ڵ����߻����ұ�
			else
			{
				if (pParent->_pLeft == pCur)
					pParent->_pLeft = pCur->_pRight;
				else
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight) //pCurֻ������
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
		else     //���Һ��Ӷ���
		{
			//���ұ�����ߵĽ������滻
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