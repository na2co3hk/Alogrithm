### 原题链接 -- [[862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/)]

### 题目概述：
Tag : 「队列」、「前缀和」

![image](https://user-images.githubusercontent.com/99656524/197925855-2c923dd4-9b2b-4679-b059-e4206b632b28.png)

### 数据范围
* $1 <= nums.length <= 10^5$
* $-10^5 <= nums[i] <= 10^5$
* $1 <= k <= 10^9$

### 解法一：单调队列 + 前缀和
这题一开始用滑动窗口做了两次都WA了，一看题解原来是方法用错了

思路和题解来自灵神，以下为自己的理解

题目大意为找到一个子数组的和大于K，一看到数组和，就要在前缀和（或者树状数组和线段树）还有滑动窗口中考虑，究竟要用哪种方法？本题数据存在负数，要是最短数组位于数组结尾部分，则无法判断左指针右移的条件导致错误。于是我们想到了前缀和，用了前缀和之后可以将区间和求出来。接下来就是枚举左右端点的区间和如果是正常暴力做法，我们还需要遍历两边数组，来枚举所有的区间和以便找到最小的子数组，这个过程可以用单调队列的数据结构去优化，排除掉一些没有用的数据，优化之后我们只需要遍历一遍数组即可完成判断，方法如下。

* 若在一个单调区间内有j < i 并且 s[i] - s[j] >= k，若有比j的下标大的数且满足>=k，则必定在j与i之前，那么j就不是最短的左端点，我们将左端点弹出，重复这一个过程

* 若在一个单调区间内有x - s[i] >= k 和x - s[j] >= k，且i的下标比j的下标大，那么j必定不是最短的左端点，因为可以选择i作为更好的答案，我们将右端点（j）弹出，重复这一过程

py代码：
```py
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        ans = inf
        s = list(accumulate(nums, initial=0))  # 计算前缀和
        q = deque()
        for i, cur_s in enumerate(s):
            while q and cur_s - s[q[0]] >= k:
                ans = min(ans, i - q.popleft())  # 优化一
            while q and s[q[-1]] >= cur_s:
                q.pop()  # 优化二
            q.append(i)
        return ans if ans < inf else -1
```

C++代码：
```cpp
class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), ans = n + 1;
        long s[n + 1];
        s[0] = 0L;
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + nums[i]; // 计算前缀和
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            long cur_s = s[i];
            while (!q.empty() && cur_s - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front(); // 优化一
            }
            while (!q.empty() && s[q.back()] >= cur_s)
                q.pop_back(); // 优化二
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用队列

