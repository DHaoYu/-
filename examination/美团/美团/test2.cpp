#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#if 0 
int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		vector<vector<int>> dp(n, vector<int>(n, 0));
		dp[0][0] = v[0].size();
		for (size_t i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (v[j - 1][v[j - 1].size() - 1] <= v[j][0])
				{
					dp[i][j] = max((unsigned)dp[i][j], dp[i][j - 1] + v[j].size());
				}
			}
		}
		cout << dp[0][n - 1] << endl;
	}
}
#endif

#if 0
int main()
{
	int a = 2;
	int b = 4;
	auto ret = [=, &a, &b]()
	{
		return a + b;
	};
	auto ret1 = [](int x, int y)
	{
		x = 20;
		y = 10;
		return x + y;
	};
	cout << ret() << " " << ret1(1, 2) << endl;
}
#endif

#if 0
#include <functional>

void print(const std::vector<int>& data, std::function<bool(int)> filter) {
	for (auto i : data) {
		if (filter(i))
			std::cout << i << std::endl;
	}
}
int main()
{
	std::vector<int> v = { 5, 10, 15, 20 };
	print(v, [](int i) { return i > 10; });     // 输出 15 20
}
#endif

#if 0
struct node
{
	int val;
	node* left;
	node* right;

	node(int v)
		:val(v)
	{}
};

node* BuildTree(int* pre, int* in, int len)
{
	node* root = new node(pre[0]);
	int pos = 0;
	while (pos < len && pre[0] != in[pos])
		++pos;
	if (pos > 0)
		root->left = BuildTree(pre + 1, in, pos);
	if (len - pos - 1 > 0)
		root->right = BuildTree(pre + pos + 1, in + pos + 1, len - pos - 1);

	return root;
}










node* Build_Tree(int* prec, int* inorder, int len)
{	//步骤1:新建根结点
	node* root = new node(prec[0]);
	//步骤2:在中序遍历中找到根结点索引，分割左右子树
	int SubTreeLen = 0;
	while (SubTreeLen < len && inorder[SubTreeLen] != prec[0])
		++SubTreeLen;

	if (SubTreeLen > 0)
	{	//步骤2:重建左子树，并且将根结点root的left指向左子树
		root->left = Build_Tree(prec + 1, inorder, SubTreeLen);
	}
	if (len - SubTreeLen - 1 > 0)
	{	//步骤2:重建右子树，并且将根结点root的left指向右子树
		root->right = Build_Tree(prec + 1 + SubTreeLen, inorder + 1 + SubTreeLen, len - SubTreeLen - 1);
	}
	return root;
}


int main()
{
	int pre[] = { 6, 5, 2, 4, 7, 8 };
	int inorder[] = { 2, 5, 4, 6, 7, 8 };
	node* root = Build_Tree(pre, inorder, 6);
	node* root1 = BuildTree(pre, inorder, 6);
	cout << " " << endl;
}
#endif