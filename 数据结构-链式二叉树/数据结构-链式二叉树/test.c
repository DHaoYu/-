#define _CRT_SECURE_NO_WARNNINGS

#include<stdio.h>
#include"BinTree.h"

int main()
{
	PBTree pRoot = NULL;
	int NodeCount = 0;
	int LeafCount = 0;
	int LeafNode_P = 0;
	int Height = 0;
	pRoot = CreatBT(pRoot);
	PrintBinTree(pRoot);
	printf("\n");
	PreOrderBinTree(pRoot);
	printf("\n");
	InOrderBinTree(pRoot);
	printf("\n");
	PostOrderBinTree(pRoot);
	printf("\n");
	printf("%d \n", NodeCount = BinTreeNodeCount(pRoot, &NodeCount));
	printf("�������ĸ߶ȣ�%d \n", Height = HeightBinTree(pRoot));
	printf("�Ƿ�Ϊƽ���������%d \n", IsBalanceTree(pRoot));
	printf("\n");
	printf("�Ƿ�Ϊƽ���������%d \n", IsBalancedTree_P(pRoot, &Height));
	printf("Ҷ�ӽ�����Ϊ��%d \n", LeafNodeCount(pRoot));
	printf("Ҷ�ӽ�����Ϊ��%d \n", LeafNodeCount_P(pRoot, &LeafNode_P));
	printf("��%d�������Ϊ��%d \n",3, GetKLevelNodeCount(pRoot, 3));
	printf("��%d�������Ϊ��%d \n", 2, GetKLevelNodeCount(pRoot, 2));
	printf("%d ", GetNode(pRoot, 'B')->data);
	DestoryBinTree(pRoot);
	printf("\n");

}