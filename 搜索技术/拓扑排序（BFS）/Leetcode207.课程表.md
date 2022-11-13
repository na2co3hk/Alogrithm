### 原题链接 -- [[207. 课程表](https://leetcode.cn/problems/course-schedule/)]

### 题目概述：
Tag : 「广度优先搜索」、「状态压缩」

![image](https://user-images.githubusercontent.com/99656524/201506862-1b9a8f94-718f-47f0-87d0-9842787f4f78.png)

### 数据范围
* $1 <= numCourses <= 10^5$
* $0 <= prerequisites.length <= 5000$
* $prerequisites[i].length == 2$
* $0 <= ai, bi < numCourses$
* $prerequisites[i] 中的所有课程对 互不相同$

### 解法一：拓扑排序
本题为拓扑排序入门题

学习某个课程前有几个前置课程，我们必须学完才能进行下一步。就像一颗横着的树，所以判断能否学完所有课程就需要将这颗树层序遍历一边，而在这种问题中的层序遍历就是拓扑排序。

和BFS很像，我们都需要一个队列，我们要先记录每个点的入度（指向这个点的边）和出度（从这个点出去的边），从入度为0（相当于一棵树的叶节点）的点开始搜索。将入度为0的点加入队列，然后将该点的入度和出度都删除，这样就会出现下一个入度为0的点，继续将他们加入队伍，直到遍历完所有的点。

C++代码：
```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>indeg(numCourses);
        for(auto p : prerequisites)
        {
            int x = p[1];
            int y = p[0];
            g[x].push_back(y);//加的是入度
            indeg[y]++;
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0;i < numCourses;i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            cnt++;
            for(auto i : g[x])
            {
                if(--indeg[i]==0)q.push(i);
            }
        }
        return cnt == numCourses;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$
