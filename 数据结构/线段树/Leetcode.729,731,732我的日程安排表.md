### 原题链接 -- [[729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i/)] -- [[731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/)] -- [[732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/)]

### 题目概述：
Tag : 「线段树」

![image](https://user-images.githubusercontent.com/99656524/201822185-364f69c4-0486-4ce8-b26d-1e20da6127bf.png)

![image](https://user-images.githubusercontent.com/99656524/201822206-dac2cd50-5269-4018-8e31-75ac7f59367a.png)

![image](https://user-images.githubusercontent.com/99656524/201822222-7995f773-e442-429d-8a76-5093dc0a01c2.png)

![image](https://user-images.githubusercontent.com/99656524/201822251-0b7361d4-8b8b-414e-bcf5-2c75de954fa2.png)

![image](https://user-images.githubusercontent.com/99656524/201822274-87ba97dd-ba20-4d11-82af-90d063a769dd.png)

![image](https://user-images.githubusercontent.com/99656524/201822301-63444f4d-f6f0-4d07-90a9-3cab7d0f6024.png)

### 数据范围
* $0 <= start < end <= 10^9$
* $每个测试用例，调用 book 函数最多不超过 400次$

### 解法一：线段树
三题的题意和题解都差不多，可以放到一起来说一下。首先是为什么能用线段树，题目给了我们一个时间段，每次调用数据结构会对时间段进行更新，并且三道题目都要进行区间查询操作，我们能想到的数据结构有差分数组、前缀和、线段树和树状数组。但是由于要维护区间的最大值，似乎就只剩下线段树了（不知道其他数据结构能不能实现维护区间最大值的操作，现在只知道线段树可以），我们将原数组分开成两半，每一半维护对应区间的区间最大值，然后对左右两边的区间都进行分半的操作。这样我们就形成了一棵树，到最后只剩下N个一个数的区间（叶节点），也就是原数组的元素，这个区间只有一个元素且最大值就是本身，这样我们就将一个数组分成了4N个部分（满二叉树），每一部分对应一段区间，每次我们更新或查询某段区间都可以将区间组合。但是由于这样空间开销是比较大的，我们可以采用动态开点（lazy结点）的方法减少空间开销，具体线段树还是找找网上吧，实现和原理都是比较复杂的这里只是简单赘述一下（其实就是菜）。

729. 我的日程安排表 I
C++代码：
```cpp
class MyCalendar {
public:
    MyCalendar() {

    }
    
    struct Node
    {
        int val;
        Node* l;
        Node* r;
        int add;
        Node():val(0),l(nullptr),r(nullptr),add(0){}
    };

    Node* root = new Node;
    int N = (int)1e9;
    bool book(int start, int end) {
        if(query(root,0,N,start,end-1)>=1)return false;
        update(root,0,N,start,end-1,1);
        return true;
    }

    void update(Node* node, int start, int end, int l, int r, int val)//将区间[l,r]的值更新（更新方式为覆盖或者加减操作）
	{
		//找到满足要求的区间
		if (l <= start && r >= end)
		{
			node->val += val;//求区间最值的时候，不需要×前面的部分
			node->add += val;//对区间进行加减操作的时候，懒标记要向下累加
			return ;
		}

		int mid = (start + end) >> 1;
		push_down(node);
		if (l <= mid)update(node->l, start, mid, l, r, val);
		if (r >= mid + 1)update(node->r, mid + 1, end, l, r, val);
		push_up(node);
	}

	int query(Node* node, int start, int end, int l, int r)//区间求和
	{
		//找到满足要求区间
		if (l <= start && r >= end)return node->val;
		int mid = (start + end) >> 1;
		int ans = 0;
		push_down(node);
		if (l <= mid)ans = query(node->l, start, mid, l, r);
		if (r >= mid + 1)ans = max(ans,query(node->r, mid + 1, end, l, r));
		return ans;
	}

    void push_down(Node* node)
    {
        if(node->l==nullptr)node->l = new Node;
        if(node->r==nullptr)node->r = new Node;
        if(node->add==0)return ;

        node->l->val +=node->add;
        node->r->val +=node->add;
        node->l->add +=node->add;
        node->r->add +=node->add;
        node->add = 0;
    }

    void push_up(Node* node)
    {
        node->val = max(node->l->val,node->r->val);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```

731. 我的日程安排表 II
C++代码：
```cpp
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    struct Node
    {
        int val;
        Node* l;
        Node* r;
        int add;
        Node():val(0),l(nullptr),r(nullptr),add(0){}
    };

    Node* root = new Node;
    int N = (int)1e9;
    bool book(int start, int end) {
        if(query(root,0,N,start,end-1)>=2)return false;
        update(root,0,N,start,end-1,1);
        return true;
    }

    void update(Node* node, int start, int end, int l, int r, int val)//将区间[l,r]的值更新（更新方式为覆盖或者加减操作）
	{
		//找到满足要求的区间
		if (l <= start && r >= end)
		{
			node->val += val;//求区间最值的时候，不需要×前面的部分
			node->add += val;//对区间进行加减操作的时候，懒标记要向下累加
			return ;
		}

		int mid = (start + end) >> 1;
		push_down(node);
		if (l <= mid)update(node->l, start, mid, l, r, val);
		if (r >= mid + 1)update(node->r, mid + 1, end, l, r, val);
		push_up(node);
	}

	int query(Node* node, int start, int end, int l, int r)//区间求和
	{
		//找到满足要求区间
		if (l <= start && r >= end)return node->val;
		int mid = (start + end) >> 1;
		int ans = 0;
		push_down(node);
		if (l <= mid)ans = query(node->l, start, mid, l, r);
		if (r >= mid + 1)ans = max(ans,query(node->r, mid + 1, end, l, r));
		return ans;
	}

    void push_down(Node* node)
    {
        if(node->l==nullptr)node->l = new Node;
        if(node->r==nullptr)node->r = new Node;
        if(node->add==0)return ;

        node->l->val +=node->add;
        node->r->val +=node->add;
        node->l->add +=node->add;
        node->r->add +=node->add;
        node->add = 0;
    }

    void push_up(Node* node)
    {
        node->val = max(node->l->val,node->r->val);
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```

731. 我的日程安排表 II
C++代码：
```
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    struct Node
    {
        int val;
        Node* l;
        Node* r;
        int add;
        Node():val(0),l(nullptr),r(nullptr),add(0){}
    };

    Node* root = new Node;
    int N = (int)1e9;
    int book(int start, int end) {
        update(root,0,N,start,end-1,1);
        return query(root,0,N,start,end-1);
    }

    void update(Node* node, int start, int end, int l, int r, int val)//将区间[l,r]的值更新（更新方式为覆盖或者加减操作）
	{
		//找到满足要求的区间
		if (l <= start && r >= end)
		{
			node->val += val;//求区间最值的时候，不需要×前面的部分
			node->add += val;//对区间进行加减操作的时候，懒标记要向下累加
			return ;
		}

		int mid = (start + end) >> 1;
		push_down(node);
		if (l <= mid)update(node->l, start, mid, l, r, val);
		if (r >= mid + 1)update(node->r, mid + 1, end, l, r, val);
		push_up(node);
	}

	int query(Node* node, int start, int end, int l, int r)//区间求和
	{
		//找到满足要求区间
		if (l <= start && r >= end)return node->val;
		int mid = (start + end) >> 1;
		int ans = 0;
		push_down(node);
		if (l <= mid)ans = query(node->l, start, mid, l, r);
		if (r >= mid + 1)ans = max(ans,query(node->r, mid + 1, end, l, r));
		return ans;
	}

    void push_down(Node* node)
    {
        if(node->l==nullptr)node->l = new Node;
        if(node->r==nullptr)node->r = new Node;
        if(node->add==0)return ;

        node->l->val +=node->add;
        node->r->val +=node->add;
        node->l->add +=node->add;
        node->r->add +=node->add;
        node->add = 0;
    }

    void push_up(Node* node)
    {
        node->val = max(node->l->val,node->r->val);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
```
* 时间复杂度： $O(nlogC)$
* 空间复杂度： $O(nlogC)$ 
