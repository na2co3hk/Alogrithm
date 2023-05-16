//区间和线段树（普通线段树）
struct Node
{
    int val, l, r;
    Node* ls;
    Node* rs;
    Node(int l, int r):l(l), r(r), val(0), ls(nullptr), rs(nullptr) {} 
};

Node* build(int l, int r)
{
    Node* root = new Node(l, r);
    if(l == r)return root;
    int mid = (l + r) / 2;
    root->ls = build(l, mid);
    root->rs = build(mid + 1, r);
    return root;
}

void update(Node* root, int l, int r, int val)
{
    if(l <= root->l and r >= root->r)
    {
        root->val += val;
        return ;
    }
    int mid = (root->l + root->r) / 2;
    if(l <= mid)update(root->ls, l, r, val);
    if(r > mid )update(root->rs, l, r, val);
    push_up(root, root->ls, root->rs);
}

int query(Node* root, int l, int r)
{
    if(l <= root->l and r >= root->r)return root->val;
    int res = 0;
    int mid = (root->l + root->r) / 2;
    if(l <= mid)res += query(root->ls, l, r);
    if(r > mid )res += query(root->rs, l, r);
    return res;
}

void push_up(Node* root, Node* ls, Node* rs)
{
    root->val = ls->val + rs->val;
}

//建树
Node* root = build(0, N);

//区间最值线段树
struct Node
{
    int val, l, r;
    Node* ls;
    Node* rs;
    Node(int l, int r):l(l), r(r), val(0), ls(nullptr), rs(nullptr) {} 
};

Node* build(int l, int r)
{
    Node* root = new Node(l, r);
    if(l == r)return root;
    int mid = (l + r) / 2;
    root->ls = build(l, mid);
    root->rs = build(mid + 1, r);
    return root;
}

void update(Node* root, int l, int r, int val)
{
    if(l <= root->l and r >= root->r)
    {
        int num = root->val;
        root->val = max(num, val);
        return ;
    }
    int mid = (root->l + root->r) / 2;
    if(l <= mid)update(root->ls, l, r, val);
    if(r > mid)update(root->rs, l, r, val);
    push_up(root, root->ls, root->rs);
}

int query(Node* root, int l, int r)
{
    if(l <= root->l and r >= root->r)return root->val;
    int res = 0;
    int mid = (root->l + root->r) / 2;
    if(l <= mid)res = max(res, query(root->ls, l, r));
    if(r > mid)res = max(res, query(root->rs, l, r));
    return res;
}

void push_up(Node* root, Node* ls, Node* rs)
{
    root->val = max(ls->val, rs->val);
}

//建树
Node* root = build(0, N);

