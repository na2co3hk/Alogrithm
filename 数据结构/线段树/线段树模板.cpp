//线段树（数组）
//将数组的分快，将数组的区间和、区间最大值分给每一块去维护

//静态树状数组，要求线段树的数组为满二叉树，所以空间花销为 4 * 原数组长度(n)
#include<iostream>
using namespace std;

const int MAX_LEN = 10010;

void build_tree(int arr[], int tree[], int node, int l, int r)//建树
{
	if (l == r) tree[node] = arr[l];//递归出口
	else
	{
		int mid = (l + r) / 2;//求出线段中点
		int ln = 2 * node + 1;//左节点
		int rn = 2 * node + 2;//右节点

		build_tree(arr, tree, ln, l, mid);//递归左半段
		build_tree(arr, tree, rn, mid + 1, r);//递归右半段
		tree[node] = tree[ln] + tree[rn];//两个叶节点的和
	}
}

void update_tree(int arr[], int tree[], int node, int l, int r, int idx, int val)//根据下标更新数组中的值
{
	if (l == r)
	{
		arr[idx] = val;
		tree[node] = val;
	}
	else
	{
		int mid = (l + r) / 2;
		int ln = 2 * node + 1;//左节点
		int rn = 2 * node + 2;//右节点
		if (idx >= l && idx <= mid)//数组下标在左半段，递归左半区间
		{
			update_tree(arr, tree, ln, l, mid, idx, val);
		}
		else//否则递归右半区间
		{
			update_tree(arr, tree, rn, mid + 1, r, idx, val);
		}
		tree[node] = tree[ln] + tree[rn];
	}
}

int query_tree(int arr[], int tree[], int node, int l, int r, int L, int R)//求L到R之间的和
{
	if (R < l || L > r)return 0;
	else if (L <= l && r <= R)return tree[node];//这一步为优化
	else if (l == r)return tree[node];
	else
	{
		int mid = (l + r) / 2;
		int ln = 2 * node + 1;//左节点
		int rn = 2 * node + 2;//右节点
		int sum_l = query_tree(arr, tree, ln, l, mid, L, R);	
		int sum_r = query_tree(arr, tree, rn, mid + 1, r, L, R);
		return sum_l + sum_r;
	}
}

int main()
{
	int arr[6] = { 1,3,5,7,9,11 };
	int size = 6;
	int tree[MAX_LEN] = { 0 };
	build_tree(arr, tree, 0, 0, size - 1);
	for (int i = 0; i < 15; i++)//15 = 2 ^ 4 - 1;4为树的高度
	{
		cout << tree[i] <<' ';
	}
	cout << endl;
	cout <<"s = " << query_tree(arr, tree, 0, 0, size - 1, 1, 3);
	return 0;
}

//-------------------------------------------------------------
//懒标记线段树（动态开点）
//在查询和更新操作的时候进行动态开点操作防止MLE
//对于表示为「区间和」且对区间进行「加减」的更新操作的情况，我们在更新节点值的时候『需要✖️左右孩子区间叶子节点的数量 (注意是叶子节点的数量)』；我们在下推懒惰标记的时候『需要累加』！！(这种情况和模版一致！！) 
//对于表示为「区间和」且对区间进行「覆盖」的更新操作的情况，我们在更新节点值的时候『需要✖️左右孩子区间叶子节点的数量 (注意是叶子节点的数量)』；我们在下推懒惰标记的时候『不需要累加』！！(因为是覆盖操作！！) 
//对于表示为「区间最值」且对区间进行「加减」的更新操作的情况，我们在更新节点值的时候『不需要✖️左右孩子区间叶子节点的数量 (注意是叶子节点的数量)』；我们在下推懒惰标记的时候『需要累加』！！

class SegementTree
{
public:
	struct Node
	{
		int val;//值
		Node* l;//左结点
		Node* r;//右结点
		int add;//懒标记
	};

	int N = (int)1e9;
	Node* root = new Node;//根结点

	void update(Node* node, int start, int end, int l, int r, int val)//将区间[l,r]的值更新（更新方式为覆盖或者加减操作）
	{
		//找到满足要求的区间
		if (l <= start && r >= end)
		{
			node->val += (end - start + 1) * val;//求区间最值的时候，不需要×前面的部分
			node->add += val;//对区间进行加减操作的时候，懒标记要向下累加
			return ;
		}

		int mid = start + end >> 1;
		//mid - start + 1 表示左孩子区间叶节点个数
		//end - mid 表示右孩子区间叶节点个数
		push_down(node, mid - start + 1, end - mid);
		if (l <= mid)update(node->l, start, mid , l, r, val);
		if (r >= mid + 1)update(node->r, mid + 1, end, l, r, val);
		push_up(node);
	}

	int query(Node* node, int start, int end, int l, int r)//区间求和
	{
		//找到满足要求区间
		if (l <= start && r >= end)return node->val;
		int mid = start + end >> 1;
		int ans = 0;
		push_down(node, mid - start + 1, end - mid);
		if (l <= mid)ans += query(node->l, start, mid, l, r);
		if (r >= mid + 1)ans += query(node->r, mid + 1, end, l, r);
		return ans;
	}

	void push_down(Node* node, int ln, int rn)//ln,rn代表左右节点的叶节点个数
	{
		//动态开点
		if (node->l == NULL)node->l == new Node;
		if (node->r == NULL)node->r == new Node;
		if (node->add==0)return;

		node->l->val += node->add * ln;//区间值修改（点修改不用+）
		node->r->val += node->add * rn;//区间值修改（点修改不用+）

		node->l->add += node->add;//加减操作累加懒标记
		node->r->add += node->add;//覆盖操作直接赋值

		node->add = 0;//标记下放完成，取消懒标记
	}

	void push_up(Node* node)//求区间最值时node->val = max(node->l->val,node->r->val);
	{
		node->val = node->l->val + node->r->val;
	}
};
