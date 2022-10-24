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

题目大意为在 $N$ 行 $N$ 列中摆放 $N$ 个皇后，每个皇后所在的行，列和两个对角线都没有其他皇后（不能相互攻击）。因为每一行只能放一个皇后，我们可以枚举每行的每一个位置，当枚举到第N行的时候还没有互相攻击，则代表一种可行解。每次放一个皇后，就标记其所在的列，主对角线和反对角线，若枚举下一行的时候有放在标记的位置上，则代表是不可行解，这个时候就要返回到上一个状态，枚举下一个位置，直到所有位置都探索过退出程序。

C++代码：
```cpp
class Solution {
public: 
    bool col[20];//列
    bool dg[20];//对角线
    bool fdg[20];//反对角线
    vector<vector<string>>res;
    vector<vector<string>> solveNQueens(int n) {
         vector<string> path(n,string(n,'.'));
         dfs(0,n,path);
         return res;
    }

    void dfs(int u,int n,vector<string>&path)
    {
        if(u==n)//只有走到叶节点才返回结果
        {
            res.push_back(path);
            return ;
        }

        for(int i = 0;i < n;i++)
        {
            if(!col[i]&&!dg[u + i]&&!fdg[n - u + i])//截距b=y+x和b=y-x为了防止出现负数加上一个偏移量
            {
                path[u][i] = 'Q';
                col[i] = dg[u + i] = fdg[n - u + i] = true;
                dfs(u + 1,n,path);
                col[i] = dg[u + i] = fdg[n - u + i] = false;
                path[u][i] = '.';
            }
        }
    }
};
```
* 时间复杂度： $O(n!)$ 
* 空间复杂度： $O(n)$ 

