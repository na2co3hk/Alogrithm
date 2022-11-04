### 原题链接 -- [[754. 到达终点数字](https://leetcode.cn/problems/reach-a-number/)]

### 题目概述：
Tag : 「二分查找」、「数学」

![image](https://user-images.githubusercontent.com/99656524/199866966-4f25acbd-4eb9-4c0b-9042-767aeea0c870.png)

### 数据范围
* $-10^9 <= target <= 10^9$
* $target != 0$

### 解法一：数学
题解思路来自灵神

根据题意，我们需要移动最小的N步到达目标，并且有往前走和往后走两种选择。记 $s$ 为当前位置，我们可以先找到大于等于 $target$ 的 $s$ ，若 $s-target$ 为奇数，那么得往回走一步，若 $s-target$ 为偶数，我们前面走的必有1步是往回走的( s - target / 2)，只要那步往回走就行，但是无论如何，我们走的次数没有变，只是方向改变了。 $target$ 正负对判断无影响，直接取一个绝对值就行。

python代码：
```py
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        s = n = 0
        while s < target or (s - target) % 2:  # 没有到达（越过）终点，或者相距奇数
            n += 1
            s += n
        return n
```

### 优化
因为需要找到 $n(n+1) >= target$ ，我们可以将他转化为一个二次函数，并用求根公式获取n的最值
