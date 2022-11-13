### 原题链接 -- [[790. 多米诺和托米诺平铺](https://leetcode.cn/problems/domino-and-tromino-tiling/)]

### 题目概述：
Tag : 「动态规划」、「找规律」

![image](https://user-images.githubusercontent.com/99656524/201463290-782a0850-2647-49a8-a3d1-bfe517de08a4.png)

![image](https://user-images.githubusercontent.com/99656524/201463305-8bddcb4e-35c4-4e0b-8a51-c5a2de9a1b74.png)

### 数据范围
* 1 <= n <= 1000

### 解法一：动态规划
题目大意为寻找摆满面积为 2 * n 的矩形的方案数，我们可以从n == 1开始手动推导一下:

![image](https://user-images.githubusercontent.com/99656524/201500902-8312b5e7-37c2-4e90-9036-2fc1bcc04216.png)

![image](https://user-images.githubusercontent.com/99656524/201500906-750b6801-3407-4907-89f7-989395d2d22e.png)

根据规律调整选中和未选中的区域，多种状态转移到一种，得到答案（图和题解来自灵神）

```python
MOD = 10 ** 9 + 7

class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1: return 1
        f = [0] * (n + 1)
        f[0] = f[1] = 1
        f[2] = 2
        for i in range(3, n + 1):
            f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD
        return f[n]
```

滚动优化
```python
MOD = 10 ** 9 + 7

class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1: return 1
        a, b, c = 1, 1, 2
        for _ in range(3, n + 1):
            a, b, c = b, c, (c * 2 + a) % MOD
        return c
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$ 
