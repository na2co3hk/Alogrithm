### 原题链接 -- [[1019. 链表中的下一个更大节点](https://leetcode.cn/problems/next-greater-node-in-linked-list/)]

### 题目概述：
Tag : 「单调栈」

![image](https://user-images.githubusercontent.com/99656524/230816912-72bc4473-824e-4a6b-afb6-e2691eca0284.png)

![image](https://user-images.githubusercontent.com/99656524/230816922-d2d51100-212a-4ece-b27a-a7f5402dee09.png)

### 数据范围
* $链表中节点数为 n$
* $1 <= n <= 10^4$
* $1 <= Node.val <= 10^9$

### 解法一：单调栈
链式的单调栈，可以先转换为数组后再套单调栈的[模板](https://github.com/na2co3hk/Alogrithm/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%88/%E5%8D%95%E8%B0%83%E6%A0%88/%E5%8D%95%E8%B0%83%E6%A0%88%E6%A8%A1%E6%9D%BF.cpp)

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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>stk;
        vector<int>nums, ans;
        for(; head; head = head->next)nums.push_back(head->val); //先转化为数组
        int n = nums.size();
        ans.resize(n);
        for(int i = n - 1;~i;i--)
        {
            while(!stk.empty() && nums[stk.top()] <= nums[i])stk.pop();
            if(!stk.empty())ans[i] = nums[stk.top()];
            stk.push(i);
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n + C)$ ,C = 6
