### 原题链接 -- [[886. 可能的二分法](https://leetcode.cn/problems/possible-bipartition/)]

### 题目概述：
Tag : 「二分图」、「深度优先搜索」

![image](https://user-images.githubusercontent.com/99656524/197371767-89c3c3dd-3cb5-4fb1-846b-e53d43a6beda.png)

### 数据范围：
* $1 <= n <= 2000$
* $0 <= dislikes.length <= 104$
* $dislikes[i].length == 2$
* $1 <= dislikes[i][j] <= n$
* $ai < bi$
* $dislikes 中每一组都 不同$

### 解法一：染色法
本题也是一道二分图的题，体现在他要将人分到两个集合中，并且在集合中不能出现"不喜欢的人"

正好这道题也可以展示一下正常的流程，先要把"人"作为点建图，对于稠密图用邻接表存图比较好，如果不知道邻接表是啥可以去看图论专题

然后进行染色，出现重叠则返回 $False$

C++代码：
```cpp
const int N = 2010, M = 20020;

class Solution {
public:
    int h[N], e[M], ne[M], idx = 0; //邻接表
    int color[N]; //表示每个点的颜色，0表示未染色，1表示红色，2表示黑色
    void add(int a,int b)
    {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    // 参数：u表示当前节点，c表示当前点的颜色
    bool dfs(int u,int c)
    {
        color[u] = c;
        for(int i = h[u];i!=-1;i = ne[i])
        {
            int j = e[i];
            if (color[j] == c) return false; //不能和讨厌的人一组
            if (color[j] == 0 && !dfs(j, 3 - c)) return false; //3-c表示对立的颜色，给讨厌的人
        }                                                      //染成对立的颜色
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        memset(h, -1, sizeof h); //点初始化为-1
        for(auto info : dislikes)
        {
            int a = info[0];
            int b = info[1];
            add(a,b); //无相图，两边都加边
            add(b,a);
        }

        for(int i = 1;i <= n;i++) //遍历所有人，对所有人进行染红色（1），中途出现不喜欢的人就染成黑色
        {                         //如果这个过程存在冲突（比如某些人已经染成黑色），则无法分成两组
            if(color[i]!=0)continue;
            if(!dfs(i,1))return false;
        }
        return true;
    }
};
```
* 时间复杂度： $O(n + m)$
* 空间复杂度： $O(n)$ 
