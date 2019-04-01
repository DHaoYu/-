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
	printf("二叉树的高度：%d \n", Height = HeightBinTree(pRoot));
	printf("是否为平衡二叉树：%d \n", IsBalanceTree(pRoot));
	printf("\n");
	printf("是否为平衡二叉树：%d \n", IsBalancedTree_P(pRoot, &Height));
	printf("叶子结点个数为：%d \n", LeafNodeCount(pRoot));
	printf("叶子结点个数为：%d \n", LeafNodeCount_P(pRoot, &LeafNode_P));
	printf("第%d层结点个数为：%d \n",3, GetKLevelNodeCount(pRoot, 3));
	printf("第%d层结点个数为：%d \n", 2, GetKLevelNodeCount(pRoot, 2));
	printf("%d ", GetNode(pRoot, 'B')->data);
	DestoryBinTree(pRoot);
	printf("\n");

}