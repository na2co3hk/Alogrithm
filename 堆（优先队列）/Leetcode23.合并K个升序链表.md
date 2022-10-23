### 原题链接 -- [[23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)]

### 题目概述：
Tag : 「链表」、「优先队列」

![image](https://user-images.githubusercontent.com/99656524/197369537-edba774e-4133-4ea8-ac38-e1227e34fa0c.png)

### 数据范围
* $k == lists.length$
* $0 <= k <= 10^4$
* $0 <= lists[i].length <= 500$
* $-10^4 <= lists[i][j] <= 10^4$
* $lists[i] 按 升序 排列$
* $lists[i].length 的总和不超过 10^4$

### 解法一：堆（优先队列）
本题是[21.合并两个升序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)的升级版

原来只需要合并两个升序链表，我们是优先考虑类似于归并排序的做法，也就是利用双指针。不过现在变成了K个链表，继续利用双指针的做法既不高效代码也复杂。于是我们必须用到另一种能够进行排序的数据结构，也就是小根堆

小根堆能够将堆里的元素自动排序，并且还能不断接受更新的链表结点

需要注意的是，我们需要对链表类的比较进行重载

C++代码
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare
    {
        bool operator()(ListNode*a,ListNode*b)
        {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*,vector<ListNode*>,compare>heap;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto x : lists)
        {
            if(x)heap.push(x);
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(!heap.empty())
        {
            ListNode* x = heap.top();
            heap.pop();
            tail->next = x;
            tail = tail->next;
            if(x->next)heap.push(x->next);
        }
        return head->next;//头节点，所以要
    }
};
```
* 时间复杂度： $O(kn×logk)$，遍历完两个链表
* 空间复杂度： $O(k)$ 
