### 原题链接 -- [[2.两数相加](https://leetcode.cn/problems/add-two-numbers/)]

### 题目概述：
Tag : 「链表」、「高精度运算」

![image](https://user-images.githubusercontent.com/99656524/196447329-03524f3e-ed83-4221-b0b0-d6302eb66b12.png)

![image](https://user-images.githubusercontent.com/99656524/196447466-198d905e-7c65-4ebf-99be-5b6bb1cc749b.png)

### 数据范围
* 每个链表中的节点数在范围 [1, 100] 内
* 0 <= Node.val <= 9
* 题目数据保证列表表示的数字不含前导零

### 解法一：高精度运算
本题为高精度运算在链表上的应用，没有过多的算法技巧
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr,*tail = nullptr;
        int t = 0;//进位
        while(l1||l2)
        {
            t += l1 ? l1->val : 0;//如果其中一个有高位不存在，就变成0
            t += l2 ? l2->val : 0;
            if (!head) {//如果头节点为空
                head = tail = new ListNode(t % 10);
            } else {//不是头节点的情况
                tail->next = new ListNode(t % 10);
                tail = tail->next;
            }
            t /=10;
            if(l1)l1 = l1->next;//l1存在就后移
            if(l2)l2 = l2->next;//l2存在就后移
        }
        if(t)tail->next = new ListNode(t);//最高位有进位
        return head;
    }
};
```
