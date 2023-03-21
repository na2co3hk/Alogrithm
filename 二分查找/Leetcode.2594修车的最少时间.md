### 原题链接 -- [[2594. 修车的最少时间](https://leetcode.cn/problems/minimum-time-to-repair-cars/)]

### 题目概述：
Tag : 「二分查找」

![image](https://user-images.githubusercontent.com/99656524/226532550-8b94c56f-f248-4122-b2b1-7bfdb336a70b.png)

![image](https://user-images.githubusercontent.com/99656524/226532581-943eead4-fda3-4433-b799-8e741b5fbfdd.png)

### 数据范围
* $1 <= ranks.length <= 10^5$
* $1 <= ranks[i] <= 100$
* $1 <= cars <= 10^6$

### 解法一：二分查找
这题中文翻译有点逆天，所以用了英文翻译，题目大意为有 $n$ 个工人，工人能力值的排名为 $ranks$ ，总共有 $cars$ 量车，一个工人能在 $r * n^2$ 时间内修理一辆车，求修理所有车的最短时间。根据题意可得：

$$
  t = r * n^2
$$
