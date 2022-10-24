### 原题链接 -- [[51. N 皇后](https://leetcode.cn/problems/n-queens/)][[52. N皇后 II](https://leetcode.cn/problems/n-queens-ii/)]

### 题目概述：
Tag : 「回溯」、「深度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/197546206-f64a0d76-12f2-4249-990a-57d692aba396.png)

![image](https://user-images.githubusercontent.com/99656524/197546266-d011bb61-c4c7-4e38-bec6-ac340d30b9c2.png)

### 数据范围
* 1 <= n <= 9

### 解法一：回溯
本题是回溯算法经典例题

简单的来说，回溯算法就是一种 “悔棋” 的算法，和深度优先搜索一样，遇到走不通的路，就进行 “悔棋” ，回到上一步的状态，然后继续进行其他路线的探索，搜集可行解，直到走完所有的路为止。回溯算法是一种暴力搜索的算法，当数据量较大的时候就不能用了。

回到本题

题目大意为在 $N$ 行 $N$ 列中摆放 $N$ 个皇后，每个皇后所在的行，列和两个对角线都没有其他皇后（不能相互攻击）。
