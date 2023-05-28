
### 原题链接 -- [[2261. 含最多 K 个可整除元素的子数组](https://leetcode.cn/problems/k-divisible-elements-subarrays/)]

### 题目概述：
Tag : 「哈希表」

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/315c0fe2-8db7-434b-8e8d-bf2a70847aad)

![image](https://github.com/na2co3hk/Alogrithm/assets/99656524/02382f43-c23d-4675-bd11-5f7cc44ac05e)

### 数据范围
* 1 <= nums.length <= 200
* 1 <= nums[i], p <= 200
* 1 <= k <= nums.length

### 解法一：哈希表
题目大意可以简化为找到符合条件的子数组的个数。对于本题，最直观的一个想法就是用一个哈希表记录所有出现的子数组，看看是否满足条件，满足条件就加入到哈希表中。最后返回哈希表的长度。

python代码：
```py
class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        n = len(nums)
        s = set()
        for i in range(n):
            cnt = 0
            for j in range(i, n):
                if nums[j] % p == 0:
                    cnt += 1
                if cnt > k:
                    break
                s.add(tuple(nums[i:j + 1]))
        return len(s)
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n)$

### 解法二：字符串哈希
基本思想也是哈希表，但是时用处理子字符串的办法去处理数组。我们可以将每个子数组看成一个 $hash key$ ，我们需要将这个 $hash key$ 转换为整型，因为整形可以有更多的空间可以避免哈希冲突。除此之外，如果用较小的 $hash key$ , 很容易就导致冲突，因此我们需要采用双hash组成64位来作为最终的hash值。

C++代码：
```cpp
class Solution {
public:
    using i64 = long long;
    const int MOD = 1e9 + 7;
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int p1 = 233, p2 = 2333;
        set<i64>s;
        for(int i = 0;i < n;i++)
        {
            for(int j = i, cnt = 0, h1 = 0, h2 = 0;j < n;j++)
            {
                if(nums[j] % p == 0)cnt++;
                if(cnt > k)break;
                h1 = (1ll * h1 * p1 + nums[j]) % MOD;
                h2 = (1ll * h2 * p2 + nums[j]) % MOD;
                s.insert(((i64)h1 << 32) | h2);
            }
        }
        return s.size();
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n)$
