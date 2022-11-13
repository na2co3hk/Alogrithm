### 原题链接 -- [[864. 获取所有钥匙的最短路径](https://leetcode.cn/problems/shortest-path-to-get-all-keys/)]

### 题目概述：
Tag : 「广度优先搜索」、「状态压缩」

![image](https://user-images.githubusercontent.com/99656524/201506862-1b9a8f94-718f-47f0-87d0-9842787f4f78.png)

### 数据范围
* 1 <= numCourses <= 10^5
* 0 <= prerequisites.length <= 5000
* prerequisites[i].length == 2
* 0 <= ai, bi < numCourses
* prerequisites[i] 中的所有课程对 互不相同

### 解法一：拓扑排序
