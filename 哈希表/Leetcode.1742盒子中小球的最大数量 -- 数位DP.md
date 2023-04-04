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
* 时间复杂度： $O(NloghighLimit)$，其中 $N = highLimit - lowLimit + 1$ 
* 空间复杂度： $O(loghighLimit)$

### 解法二：动态规划
既然要计算数位和，就不得不提到数位DP了，我们直接枚举桶的编号，然后再填数字，统计区间内的每个数的数位和是属于哪个桶的就行了

python代码：
```py
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        s = str(highLimit)
        t = str(lowLimit)
        if len(t) < len(s): #在前面补0用来和上界对齐
            t = '0' * (len(s) - len(t)) + t
        @cache  #寻找有多少个数位和属于这个桶（一共45个桶）
        def f(i: int, up_limit: bool, down_limit, is_num: bool, sum: int) -> int:
            if sum < 0: 
                return 0
            if i == len(s):
                return int(is_num and sum == 0) #sum == 0 代表这个数位和属于这个桶
            up = int(s[i]) if up_limit else 9 #上界，上一位数达到上界，这一位就只能填到s[i]
            down = int(t[i]) if down_limit or not is_num else 0 #下界，上一位数达到下界，这一位就只能填到t[i]
            res = 0
            for d in range(down, up+1):
                res += f(i + 1, up_limit and d == up, down_limit and d == down, is_num or d > 0, sum - d)
            return res
        return max(f(0, True, True, False, i) for i in range(46))
```
* 时间复杂度： $O(N^2)$，其中 $N = highLimit - lowLimit + 1$ ，不一定对
* 空间复杂度： $O(N^2)$

