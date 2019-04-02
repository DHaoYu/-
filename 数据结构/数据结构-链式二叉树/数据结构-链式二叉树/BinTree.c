#define _CRT_SECURE_NO_WARNNINGS 

#include"BinTree.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

BTree*  BuyNewBTNode(BTypeData data)
{
	BTree* NewBNode = (BTree*)malloc(sizeof(BTree));
	NewBNode->data = data;
	NewBNode->LeftChild = NULL;
	NewBNode->RightChild = NULL;
	return NewBNode;
}

BTree* CreatBinTree(BTypeData *array, int* size, int* pos)//����������
{
	PBTree pRoot = NULL;

		if ((*size) >= 0 && array[*pos] != '#')
		{
			pRoot = BuyNewBTNode(array[*pos]);
			(*size)--;
			(*pos)++;
			pRoot->LeftChild = CreatBinTree(array, size, pos);	
			(*size)--;
			(*pos)++;
			pRoot->RightChild = CreatBinTree(array, size, pos);
		}
		else
			pos++;

		return pRoot;
}


BTree* CreatBT(PBTree pRoot)
{
	BTypeData array[] = { 'A', 'B', 'D', '#','#','#', 'C', 'E', '#', '#', 'F', '#', '#' };
	//BTypeData array[] = { 'A', 'B', 'D', '#', '#', 'G', '#', '#','C', 'E', '#', '#', 'F', '#', '#' };
	//BTypeData array[] = { 'A', 'B', 'D', 'C', '#', '#' };
	int size = sizeof(array) / sizeof(array[0]) - 1;
	int pos = 0;
	return pRoot = CreatBinTree(array, &size, &pos);
}


BTree* DestoryBinTree(PBTree pRoot)//���ٶ�����
{
	if (pRoot != NULL)
	{
		DestoryBinTree(pRoot->LeftChild);
		DestoryBinTree(pRoot->RightChild);
		free(pRoot);
	}
	return pRoot;
}

void PreOrderBinTree(PBTree pRoot)//ǰ�����������
{
	if (pRoot != NULL)
	{
		printf("%c ", pRoot->data);
		PreOrderBinTree(pRoot->LeftChild);
		PreOrderBinTree(pRoot->RightChild);
	}

}


BTree* InOrderBinTree(PBTree pRoot)//�������������
{
	if (pRoot != NULL)
	{
		InOrderBinTree(pRoot->LeftChild);
		printf("%c ", pRoot->data);
		InOrderBinTree(pRoot->RightChild);
	}

	return pRoot;
}

BTree* PostOrderBinTree(PBTree pRoot)//�������������
{
	if (pRoot != NULL)
	{
		PostOrderBinTree(pRoot->LeftChild);
		PostOrderBinTree(pRoot->RightChild);
		printf("%c ", pRoot->data);
	}

	return pRoot;
}

//void LevelOrderBinTree(PBTree pRoot)//�������������
//{
//	if (pRoot != NULL)
//	{
//		printf("%c ", pRoot->data);
//	}
//}

int BinTreeNodeCount(PBTree pRoot,int *Count)
{
	if (pRoot != NULL)
	{
		(*Count)++;
		BinTreeNodeCount(pRoot->LeftChild, Count);
		BinTreeNodeCount(pRoot->RightChild, Count);
	}
	return (*Count);
}

/*
	����--->�������
	int height(PBTree pRoot)
	{
		int left=0,right=0;
*/

int HeightBinTree(PBTree pRoot)
{
	int Left = 0;
	int Right = 0;
	if (NULL == pRoot)
		return 0;

	Left = HeightBinTree(pRoot->LeftChild);
	Right = HeightBinTree(pRoot->RightChild);

	return Left > Right ? Left + 1 : Right + 1;
}


//int HeightBinTree(PBTree pRoot)//��ȡ�������ĸ߶�---��������е�����
//{
//	int Llength, Rlength;
//	if (pRoot == NULL)
//		return 0;
//
//		Llength = HeightBinTree(pRoot->LeftChild);
//		Rlength = HeightBinTree(pRoot->RightChild);
//
//	if (Rlength > Llength)
//		return Rlength + 1;
//	else
//		return Llength + 1;
//
//}

int IsBalanceTree(PBTree pRoot)//�Ƿ�Ϊƽ�������
{
	int LHeight = 0;
	int RHeight = 0;

	if (pRoot == NULL)
		return 1;
	
	LHeight = HeightBinTree(pRoot->LeftChild);
	RHeight = HeightBinTree(pRoot->RightChild);

	return abs(RHeight - LHeight) < 2
		&& IsBalanceTree(pRoot->LeftChild)
		&& IsBalanceTree(pRoot->RightChild);

}

int IsBalancedTree_P(PBTree pRoot,int *Height)
{
	int IsLeftBalance = 0;
	int IsRightBalance = 0;
	int LeftHeight = 0;
	int RightHeight = 0;
	
	if (NULL == pRoot)
		return 1;

	IsLeftBalance = IsBalancedTree_P(pRoot->LeftChild, &LeftHeight);
	IsRightBalance = IsBalancedTree_P(pRoot->RightChild, &RightHeight);

	if (IsLeftBalance && IsRightBalance && abs(LeftHeight - RightHeight) < 2)
	{
		*Height = LeftHeight>RightHeight ? LeftHeight + 1 : RightHeight + 1;
		return 1;
	}
	else
		return 0;
}

int LeafNodeCount(PBTree pRoot)//��ȡҶ�ӽڵ�ĸ���
{
	int Lcount = 0;
	int Rcount = 0;

	if (NULL == pRoot)
		return Lcount+Rcount;

	Lcount=LeafNodeCount(pRoot->LeftChild);
	Rcount=LeafNodeCount(pRoot->RightChild);
	
	if (NULL == pRoot->LeftChild && NULL == pRoot->RightChild)
		Lcount++;

	return Lcount+Rcount;
}

int LeafNodeCount_P(PBTree pRoot, int* count)
{
	if (NULL == pRoot)
		return (*count);

	LeafNodeCount_P(pRoot->LeftChild, count);
	LeafNodeCount_P(pRoot->RightChild, count);

	if (NULL == pRoot->LeftChild && NULL == pRoot->RightChild)
		(*count)++;

	return (*count);
}

int GetKLevelNodeCount(PBTree pRoot, int k)//��ȡ��K�������
{
	if (NULL == pRoot || k <= 0)
		return 0;

	if (1 == k)
		return 1;

	return GetKLevelNodeCount(pRoot->LeftChild, k - 1) + GetKLevelNodeCount(pRoot->RightChild, k - 1);
}

BTree* GetNodeParent(PBTree pRoot, PBTree pNode)//���pNode���׽��
{
	if (NULL == pRoot || pNode == NULL)
		return NULL;

	if (pRoot->LeftChild == pNode || pRoot->RightChild == pNode)
		return pRoot;

	if (GetNodeParent(pRoot->LeftChild, pNode) != NULL)
		return pRoot;
	else
	return GetNodeParent(pRoot->RightChild, pNode);

}

BTree* GetNode(PBTree pRoot, BTypeData data)//��ȡ��һ��dataֵ�Ľ��
{
	if (NULL == pRoot)
		return NULL;

	if (pRoot->data == data)
		return pRoot;

	if (NULL != GetNode(pRoot->LeftChild, data))
		return pRoot;
	return GetNode(pRoot->RightChild, data);
}

BTree* PrintBinTree(PBTree pRoot)//��ӡ������
{
	if (pRoot != NULL )
	{
		printf("%c ", pRoot->data);
		PrintBinTree(pRoot->LeftChild);
		PrintBinTree(pRoot->RightChild);
	}

		return pRoot;
}

