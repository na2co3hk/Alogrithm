### 原题链接 -- [[21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)]

### 题目概述：
Tag : 「递归」

![image](https://user-images.githubusercontent.com/99656524/197214277-9f3b04ee-10cc-407c-b1b6-27eb71c80767.png)

![image](https://user-images.githubusercontent.com/99656524/197214311-5685d34b-ce8e-4643-b7fb-30ac061040f2.png)

### 数据范围
* 两个链表的节点数目范围是 [0, 50]
* -100 <= Node.val <= 100
* l1 和 l2 均按 非递减顺序 排列

### 解法一：递归
看到合并和有序，第一时间该想到的是归并排序，所以我们应该写一个类似于归并排序的递归

我们用两个指针p1和p2分别指向l1和l2的头节点，若p1->val > p2->val，我们就将p2作为合并后的头节点，并且让p2链接到p1之后。反之则将p1作为合并后的头节点，并让p1链接到p2之后

C++代码：
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) { //递归出口
            return l2;
        } else if (l2 == nullptr) { //递归出口
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2); //链接
            return l1; //返回头节点
        } else {
            l2->next = mergeTwoLists(l1, l2->next); //链接
            return l2; //返回头节点
        }
    }
};

```
* 时间复杂度： $O(n + m)$，遍历完两个链表
* 空间复杂度： $O(n + m)$ 
