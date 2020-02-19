
#if 0
typedef class TreeNode
{
public:
	TreeNode(const int& data)
	: val(data)
	, left(nullptr)
	, right(nullptr)
	{}
	int val;
	TreeNode* left;
	TreeNode* right;
}Node;

int sum = 0;

Node* dfs(Node* root)
{
	if (root == nullptr)
		return nullptr;
	Node* left = dfs(root->left);
	Node* right = dfs(root->right);
	if ((left != nullptr && left->left == nullptr && left->right == nullptr) ||
		(right != nullptr && right->left == nullptr && right->right == nullptr))
		sum += root->val;
	return root;
}

void Func(Node* n1)
{
	dfs(n1);
}

int main()
{
	Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	Func(&n1);
}
#endif