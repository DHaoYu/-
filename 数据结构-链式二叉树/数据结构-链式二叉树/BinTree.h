#define _CRT_SECURE_NO_WARNNINGS 

typedef char BTypeData;

typedef struct BinTree
{
	struct BinTree *LeftChild;
	struct BinTree *RightChild;
	BTypeData data;
}BTree,*PBTree;

BTree* CreatBinTree(BTypeData *array,int * size,int * pos);//����������----2

BTree* CreatBT(PBTree pRoot);//����������---1

BTree* DestoryBinTree(PBTree pRoot);//���ٶ�����

void PreOrderBinTree(PBTree pRoot);//ǰ�����������//���з�������Ҳ���൱�ں������н���

BTree* InOrderBinTree(PBTree pRoot);//�������������

BTree* PostOrderBinTree(PBTree pRoot);//�������������

BTree* PrintBinTree(PBTree pRoot);//ǰ�������ӡ������

void LevelOrderBinTree(PBTree pRoot);//�������������

int BinTreeNodeCount(PBTree pRoot,int *Count);//��ý�����

int HeightBinTree(PBTree pRoot);//��ȡ�������ĸ߶�

int IsBalanceTree(PBTree pRoot);//�Ƿ�Ϊƽ�������

int IsBalancedTree_P(PBTree pRoot, int *Height);//�����汾�ж϶������Ƿ�ƽ��

int LeafNodeCount(PBTree pRoot);//���Ҷ�ӽڵ�ĸ���
int LeafNodeCount_P(PBTree pRoot, int* count);//��ȡҶ�ӽ�����_P

int GetKLevelNodeCount(PBTree pRoot, int k);//��ȡ��K��ڵ����

BTree* GetNodeParent(PBTree pRoot, PBTree pNode);//���pNode���׽��

BTree* GetNode(PBTree pRoot, BTypeData data);//��ȡ��һ��dataֵ�Ľ��


/*
// 1. ���� 
BTNode* CreateBinTree(BTDataType* array, int size);
BTNode* CopyBinTree(BTNode* pRoot);
void DestroyBinTree(BTNode** pRoot);
// �����������ֱ�����ʽ 
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