#define _CRT_SECURE_NO_WARNNINGS 

typedef char BTypeData;

typedef struct BinTree
{
	struct BinTree *LeftChild;
	struct BinTree *RightChild;
	BTypeData data;
}BTree,*PBTree;

BTree* CreatBinTree(BTypeData *array,int * size,int * pos);//创建二叉树----2

BTree* CreatBT(PBTree pRoot);//创建二叉树---1

BTree* DestoryBinTree(PBTree pRoot);//销毁二叉树

void PreOrderBinTree(PBTree pRoot);//前序遍历二叉树//其中返回树根也就相当于函数运行结束

BTree* InOrderBinTree(PBTree pRoot);//中序遍历二叉树

BTree* PostOrderBinTree(PBTree pRoot);//后序遍历二叉树

BTree* PrintBinTree(PBTree pRoot);//前序遍历打印二叉树

void LevelOrderBinTree(PBTree pRoot);//层序遍历二叉树

int BinTreeNodeCount(PBTree pRoot,int *Count);//获得结点个数

int HeightBinTree(PBTree pRoot);//获取二叉树的高度

int IsBalanceTree(PBTree pRoot);//是否为平衡二叉树

int IsBalancedTree_P(PBTree pRoot, int *Height);//升级版本判断二叉树是否平衡

int LeafNodeCount(PBTree pRoot);//获得叶子节点的个数
int LeafNodeCount_P(PBTree pRoot, int* count);//获取叶子结点个数_P

int GetKLevelNodeCount(PBTree pRoot, int k);//获取第K层节点个数

BTree* GetNodeParent(PBTree pRoot, PBTree pNode);//获得pNode父亲结点

BTree* GetNode(PBTree pRoot, BTypeData data);//获取第一个data值的结点


/*
// 1. 创建 
BTNode* CreateBinTree(BTDataType* array, int size);
BTNode* CopyBinTree(BTNode* pRoot);
void DestroyBinTree(BTNode** pRoot);
// 二叉树的三种遍历方式 
void PreOrder(BTNode* pRoot);
void PreOrderNor(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);
int GetNodeCount(BTNode* pRoot);
int Height(BTNode* pRoot);
int IsBalanceTree(BTNode* pRoot);
int IsBalanceTree_P(BTNode* pRoot, int* height);
int GetLeafNodeCount(BTNode* pRoot);
int GetKLevelNodeCount(BTNode* pRoot, int K);
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);
BTNode* GetNode(BTNode* pRoot, BTDataType data);
void Mirror(BTNode* pRoot);
*/