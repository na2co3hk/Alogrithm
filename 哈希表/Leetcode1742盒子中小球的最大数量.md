### 原题链接 -- [[1742. 盒子中小球的最大数量](https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/)]

### 题目概述：
Tag : 「哈希表」、「动态规划」

![image](https://user-images.githubusercontent.com/99656524/203469572-013d3a97-aa00-479c-8733-aeabb573a8e0.png)

![image](https://user-images.githubusercontent.com/99656524/203469586-40e10875-fad0-4adb-97ae-570e7fe3fb2f.png)

### 数据范围
* $1 <= lowLimit <= highLimit <= 10^5$

### 解法一：哈希表
题目大意为统计每个数的数位和属于哪个桶，我们直接用哈希表来模拟这个过程就行了，由于这道题数据范围只有 $10^5$ 我们只需要用到 5 * 9 = 45 个桶就够了，用数组模拟哈希表会更快，这里就不演示了捏（蓝狗是这样的）

C++代码：
```cpp
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int ,int >hash;
        int mx = -1;
        for(int i = lowLimit;i <= highLimit;i++)
        {
            int x = i, ans = 0;
            while(x)
            {
                ans += x%10;
                x /= 10;
            }
            hash[ans]++;
            mx = max(hash[ans], mx);
        }
        return mx;
    }
};
```
* 时间复杂度： $O(logn)$
* 空间复杂度： $O(1)$
