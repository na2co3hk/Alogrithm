### 原题链接 -- [[6432. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components/)]

### 题目概述：
Tag : 「深度优先搜索」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/5647914f-9dc7-44c6-8501-937e6481338f)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/35944724-47c0-4fcb-a89c-eaa34ad26640)

### 数据范围
* 1 <= n <= 50
* 0 <= edges.length <= n * (n - 1) / 2
* edges[i].length == 2
* 0 <= ai, bi <= n - 1
* ai != bi
* 不存在重复的边

### 解法一：深度优先搜索
完全连通分量可以看作是，任意两点间都存在一条边。设一个连通图中点的数量为v，边的数量为e，则可以用组合数公式表示成 $e = {v \choose 2}$ ，因此，只要用深度遍历搜索找出所有连通图点的数量和边的数量就可以了。

C++代码：
```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto & edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<bool>vis(n);
        int ans = 0, v , e; //v表示点,e表示边
        function<void(int x)>dfs = [&](int x)
        {
            vis[x] = true;
            v++;
            e += g[x].size();
            for(int y:g[x])
            {
                if(!vis[y])dfs(y);
            }
        };

        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                v = 0;
                e = 0;
                dfs(i);
                ans += (e == v * (v - 1));
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n + m)$ 
* 空间复杂度： $O(n + m)$

### 解法二：广度优先搜索
同样，也可以用广度优先搜索进行遍历图

C++代码：
```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto & edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<bool>vis(n);
        int ans = 0, v , e; //v表示点,e表示边
        function<void(int x)>bfs = [&](int x)
        {
            queue<int>q;
            q.push(x);
            vis[x] = true;
            while(!q.empty())
            {
                auto p = q.front();
                q.pop();
                v++;
                for(int y : g[p])
                {
                    e++;
                    if(!vis[y])q.push(y);
                    vis[y] = true;
                }   
            }
        };

        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                v = 0;
                e = 0;
                bfs(i);
                ans += (e == v * (v - 1));
            }
        }
        return ans;
    }
};
```
* 时间复杂度： $O(n + m)$ 
* 空间复杂度： $O(n + m)$
