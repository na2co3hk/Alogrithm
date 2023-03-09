### 原题链接 -- [[2379. 得到 K 个黑块的最少涂色次数](https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)]

### 题目概述：
Tag : 「滑动窗口」

![image](https://user-images.githubusercontent.com/99656524/223942593-7471d807-e825-432a-9efb-44265ba9d734.png)

### 数据范围
* n == blocks.length
* 1 <= n <= 100
* blocks[i] 要么是 'W' ，要么是 'B' 。
* 1 <= k <= n

### 解法一：滑动窗口
题目大意为找到一个修改部分元素后长度为K的序列，并且序列字符只包含'B'，求修改的'W'的最少个数。由于题目要求序列长度必定为K，我们可以用固定长度的滑动窗口来解决这道题。这样题目就转变成利用长度为K的滑动窗口求出'B'字母出现的最大次数，然后用窗口长度（也就是K）减去'B'出现的最大次数即可求得要修改的'W'的最少次数。（其实只用一个变量统计'B'出现的次数即可）
C++代码：
```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int WB[2] = {0};
        for(int i = 0;i < k;i++)blocks[i] == 'B' ? WB[0]++ : WB[1]++;
        int MAX = WB[0],l = 0, r = k;
        while(r < n)
        {
            blocks[r] == 'B' ? WB[0]++ : WB[1]++;
            blocks[l] == 'B' ? WB[0]-- : WB[1]--;
            MAX = max(WB[0], MAX);
            r++;
            l++;
        }
        return MAX > k ? 0 : k - MAX;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(1)$
