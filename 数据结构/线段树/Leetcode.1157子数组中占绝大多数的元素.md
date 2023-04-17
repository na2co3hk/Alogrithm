### 原题链接 -- [[1157. 子数组中占绝大多数的元素](https://leetcode.cn/problems/online-majority-element-in-subarray/)]

### 题目概述：
Tag : 「线段树」、「二分查找」、「摩尔投票」

![image](https://user-images.githubusercontent.com/99656524/232356152-474b6209-81a0-47d7-bee2-9e237d6ec994.png)

### 数据范围
* $1 <= arr.length <= 2 * 104$
* $1 <= arr[i] <= 2 * 104$
* $0 <= left <= right < arr.length$
* $threshold <= right - left + 1$
* $2 * threshold > right - left + 1$
* $调用 query 的次数最多为 104$ 

### 解法一：线段树 + 摩尔投票 + 二分查找
观察题目可以得出这是一道区间查询问题，而且需要设计数据结构实现高效查询，那么适合的数据结构只有前缀和类的数据结构，这里官解使用的是线段树。而区间查询的元素为子数组中占多数的元素，可以利用摩尔投票算法来得出一个数组中占多数的元素，但只使用摩尔投票算法只能得出区间内占多数的元素，并不能确定其是否真的满足 $query$ 的 $threshold$ ，因此还需要用哈希表统计各个元素出现的下标，然后二分查找找到查询区间 $l$ 和 $r$ ，区间大小就代表了占多数元素的出现次数，若出现次数大于 $threshold$ 则代表满足条件，否则返回-1。

C++代码：
```cpp
struct Node {
    Node(int x = 0, int cnt = 0): x(x), cnt(cnt) {}
    Node& operator+=(const Node& that) { //摩尔投票
        if (x == that.x) {
            cnt += that.cnt;
        }
        else if (cnt >= that.cnt) {
            cnt -= that.cnt;
        }
        else {
            x = that.x;
            cnt = that.cnt - cnt;
        }
        return *this;
    }

    int x, cnt;
};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): arr(arr) {
        n = arr.size();
        for (int i = 0; i < n; ++i) {
            loc[arr[i]].push_back(i);
        }

        tree.resize(n * 4);
        seg_build(0, 0, n - 1);
    }
    
    int query(int left, int right, int threshold) {
        Node ans;
        seg_query(0, 0, n - 1, left, right, ans);
        vector<int>& pos = loc[ans.x];
        int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left); //二分查找找到对应区间，区间大小即出现次数
        return (occ >= threshold ? ans.x : -1);
    }

private:
    int n;
    const vector<int>& arr;
    unordered_map<int, vector<int>> loc;
    vector<Node> tree;

    void seg_build(int id, int l, int r) {
        if (l == r) {
            tree[id] = {arr[l], 1};
            return;
        }

        int mid = (l + r) / 2;
        seg_build(id * 2 + 1, l, mid);
        seg_build(id * 2 + 2, mid + 1, r);
        tree[id] += tree[id * 2 + 1];
        tree[id] += tree[id * 2 + 2];
    }

    void seg_query(int id, int l, int r, int ql, int qr, Node& ans) {
        if (l > qr || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            ans += tree[id]; //利用线段树统计答案
            return;
        }

        int mid = (l + r) / 2;
        seg_query(id * 2 + 1, l, mid, ql, qr, ans);
        seg_query(id * 2 + 2, mid + 1, r, ql, qr, ans);
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```
* 时间复杂度： $O(n + qlogn)$ ，其中n是数组arr长度，q是查询次数，预处理哈希表和线段树需要 $O(n)$ 的时间，每次查询需要 $O(logn)$ 的时间 
* 空间复杂度： $O(n)$ ，为哈希表和线段树使用的空间
