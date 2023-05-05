### 原题链接 -- [[2662. 前往目标的最小代价](https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads/)]

### 题目概述：
Tag : 「最短路径」、「图」

![image](https://user-images.githubusercontent.com/99656524/236482918-f90d6312-07fa-4fbf-b872-0d21981ee213.png)


### 数据范围
* $start.length == target.length == 2$
* $1 <= startX <= targetX <= 10^5$
* $1 <= startY <= targetY <= 10^5$
* $1 <= specialRoads.length <= 200$
* $specialRoads[i].length == 5$
* $startX <= x1i, x2i <= targetX$
* $startY <= y1i, y2i <= targetY$
* $1 <= costi <= 10^5$

### 解法一：Dijkstra算法
题解来源与[灵神题解](https://leetcode.cn/problems/minimum-cost-of-a-path-with-special-roads/solution/zhi-jie-qiu-zui-duan-lu-wu-xu-jian-tu-by-i8h7/)，以下是我的一些理解。

题目给了一些特殊路径，这些特殊路径可能是陷阱也可能是捷径，我们只需要在走特殊路径到终点和不走特殊路径到终点取一个 $min$ ，这样就完成了找最短边的任务，然后再不断更新到终点的最小值。

C++代码：
```cpp
class Solution {
public:
    using i64 = long long;
    const i64 mask = (i64)2 << 31; //2**32 - 1即32位最大值
    int cost(int x1, int y1, int x2, int y2)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    }
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        i64 t = (i64)target[0] << 32 | target[1]; //64位存坐标，当成一个点
        i64 s = (i64)start[0] << 32 | start[1];
        unordered_map<i64, int>dist = {{s, 0}, {t, INT_MAX}};
        unordered_set<i64>st;
        while(1) //直到找到为止退出
        {
            i64 x = -1;
            int dx = -1; //相当于dist[x]
            for(auto &[y, dy] : dist)
            {
                if(!st.count(y) and (dx < 0 or dy < dx))
                {
                    x = y;
                    dx = dy;
                }
            }
            if(x == t)return dx;
            st.insert(x);
            int xi = x >> 32; //右移32位恢复成x
            //int xj = x & UINT32_MAX;//与MAX去掉高位恢复成y
            int xj = x & (mask - 1);
            int c = cost(xi, xj, target[0], target[1]);
            dist[t] = min(dist[t], dx + c); //更新x到终点的最短路
            for(auto &r : specialRoads)
            {
                int d = dx + cost(r[0], r[1], xi, xj) + r[4]; //走特殊路径
                i64 w = (i64)r[2] << 32 | r[3];
                if(!dist.count(w) or d < dist[w])dist[w] = d; //对比走特殊路径和不走特殊路径的距离
            }

        }
    }
};
```
* 时间复杂度： $O(n^2)$
* 空间复杂度： $O(n)$
