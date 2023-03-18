### 原题链接 -- [[560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)]

### 题目概述：
Tag : 「前缀和」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/226074139-bb00fe98-3385-4b2e-9e11-667e2bbe3a50.png)

![image](https://user-images.githubusercontent.com/99656524/226074148-63251b0d-afcf-4e3f-a93c-e4423dbb519d.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^9$
* $1 <= p <= 10^9$

### 解法一：前缀和 + 哈希表
题目大意为找到一个最短的子数组，使得删掉该子数组后的数组和可以整除 P 。遇到这种将数组分成两类的可以用前缀和 + 哈希表的方法来解答，和其他题目相似。本题运用了一点同余的知识。

#### 同余
两个数除以同一个数出现余数相同的情况，即， $x(modp) = y(modp)$ ，记作：

$$
   x ≡ y (mod p)
$$

此外， $(x-y)modp = 0$ 也属于同余，与 $x(modp) = y(modp)$ 等价

回到本题，设x为整个数组的和，y为被删掉子数组的和，根据上面的定义不难发现x和y同余，而y又是一段区间的区间和，用前缀和表示为

$$
    s[r] - s[l] ≡  x (mod p)
$$

移项得

$$
   s[r] - x ≡ s[l] (mod p)
$$

这样就将问题转换再次转换为两数之和了。

C++代码：
```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int>pre(n + 1);
        for(int i = 1;i <= n;i++)pre[i] = (pre[i-1] + nums[i-1]) % p;//先mod p一遍，再+p，就可以将负数转换为正数，并且还可以防止溢出
        int x = pre[n];
        if(x == 0)return 0;//移除空子数组
        int ans = INT_MAX;
        unordered_map<int, int>hash;
        for(int i = 0;i <= n;i++)
        {
            auto it = hash.find((pre[i] - x + p) % p);
            if(it != hash.end())ans = min(ans, i - it->second);
            hash[pre[i]] = i;
        }
        return ans < n ? ans : -1;
    }
};
```
* 时间复杂度： $O(n)$ 
* 空间复杂度： $O(n)$ 

