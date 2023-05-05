### 原题链接 -- [[743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/)]

### 题目概述：
Tag : 「最短路径」、「图」

![image](https://user-images.githubusercontent.com/99656524/236367053-e9c2dc3f-f47f-4e99-b908-881a28bf46ef.png)

![image](https://user-images.githubusercontent.com/99656524/236367074-9b2a7be1-4dee-4027-8e47-dcb4e4f1ca1d.png)

### 数据范围
* 1 <= k <= n <= 100
* 1 <= times.length <= 6000
* times[i].length == 3
* 1 <= ui, vi <= n
* ui != vi
* 0 <= wi <= 100
* 所有 (ui, vi) 对都 互不相同（即，不含重复边）

### 解法一：朴素Dijkstra算法
迪杰斯特拉模板题

题目大意可以转换为求k点到其余所有点最短路径的最大值，因此可以用Dijkstra算法求出k点到其余所有点的最短路径后取最大值即可。

C++代码：
```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           const int inf = INT_MAX / 2;//正无穷（防止溢出）

           //邻接数组存图
           vector<vector<int>>graph(n+1,vector<int>(n+1,inf));//距离全都初始化为正无穷先
           for(auto & time : times)
           {
               int x = time[0];//行
               int y = time[1];//列
               graph[x][y] = time[2];//权重
           }
           
           //用来存各个点之间当前的距离
           vector<int>distance(n+1,inf);

           //查看各点是否被标记
           vector<bool>visited(n+1);

           //源节点与本身距离为0
           distance[k] = 0;

           //dijkstra（迪杰斯特拉）算法
           for(int i = 1;i <= n; i++)
           {
               // 在还未确定最短路的点中，寻找距离最小的点
               int x = -1;
               for(int y = 1;y <= n; y++)
               {
                   if(!visited[y]&&(x == -1 || distance[y] < distance[x]))//x点能够到达y点点并且y点还没被标记
                   {
                          x = y;//将y赋值给x，更新上一个顶点
                   }
               }

               visited[x]=true;//上一个顶点标记为已访问
               for(int y = 1;y <= n; y++)
               {
                   distance[y]=min(distance[y],distance[x]+graph[x][y]);//更新最小距离
               }
           }
           
           // 找到距离最远的点
           int ans = 0;
           for(int i = 1;i <= n;i++)
           {
               ans = max(ans,distance[i]);
           }
           return ans >= inf ? -1 : ans;
    }
};
```
* 时间复杂度： $O(n^2)$
* 空间复杂度： $O(n^2)$

