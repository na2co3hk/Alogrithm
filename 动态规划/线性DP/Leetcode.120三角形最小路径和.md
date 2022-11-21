### 原题链接 -- [[120. 三角形最小路径和](https://leetcode.cn/problems/triangle/solution/san-jiao-xing-zui-xiao-lu-jing-he-by-leetcode-solu/)]

### 题目概述：
Tag : 「动态规划」

![image](https://user-images.githubusercontent.com/99656524/203083444-fd065915-93da-4421-a747-0e0d1bd9f0b8.png)

### 数据范围
* $1 <= triangle.length <= 200$
* $triangle[0].length == 1$
* $triangle[i].length == triangle[i - 1].length + 1$
* $-10^4 <= triangle[i][j] <= 10^4$

### 解法一：动态规划
很经典的动态规划题，并且很多地方值得学习

本题属于动态规划最短路径中的数字三角形模型，我们首先把三角形往左边“推”，形成一个等腰三角形
```
[2]
[3,4]
[6,5,7]
[4,1,8,3]
```
很显然可以看出来，下一层的数字之和只能由左上角的数字之和或者上面的数字之和转移过来，这就是一种状态转移过程，得到的状态转移方程：

$$
f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j]
f[i][i] = f[i-1][i-1] + triangle[i][i]
$$

第一种情况是正常情况，第二种是特判三角形斜边上的数值的转移（因为没有上方转移过来，只能由左上角转移过来），最后计算最后一行最小值即是最短路径

C++代码：
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0]; //每行初始化
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j]; //正常转移
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i]; //斜边的转移
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n^2)$ 

### 优化
对于本题，有两个优化方法：

1.由于状态转移只与f[i-1]这个状态有关，而不是与f[i-2]或之前的状态有关，我们可以进行滚动优化，将状态转移的维度减少一维，这样状态转移方程就变成了

$$
f[j] = min(f[j - 1], f[j]) + triangle[i][j]
$$

2.我们可以在从三角底部向上推导，这样最后只会有一个结果（及左上角的元素），不用再在最后一行计算最小值，这样状态转移方程就变成了

$$
f[j] = min(f[j + 1], f[j]) + triangle[i][j]
$$

C++代码：
```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; i --)
            for(int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n)$ 
