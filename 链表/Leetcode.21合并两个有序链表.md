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
