### 原题链接 -- [[2602. 使数组元素全部相等的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/)]

### 题目概述：
Tag : 「前缀和」、「二分查找」

![image](https://user-images.githubusercontent.com/99656524/230751864-8784b529-2c19-40c5-9f08-c891111b2c16.png)

![image](https://user-images.githubusercontent.com/99656524/230751868-d534195b-6db5-4608-b0d0-281c406af693.png)

### 数据范围
* $n == nums.length$
* $m == queries.length$
* $1 <= n, m <= 10^5$
* $1 <= nums[i], queries[i] <= 10^9$

### 解法一：前缀和 + 二分查找
题目大意可以转换为组成一个面积为 $quries[i] * n$ 的矩形。看到题目第一反应应该是枚举，但是枚举需要 $n^2$ 的复杂度 ，对于题目数据 $10^5$ 是无法接受的，所以需要数据结构去优化。

由于题目中答案和数组顺序无关，我们可以考虑先给数组排个序，然后将数组看成一个柱状图，结合刚才提到的题目大意转换，我们只需要求出组成 $quries[i] * n$ 缺少的面积和多出来的面积即可，而柱状图的总面积可以用前缀和求得，接下来就是考虑一个临界条件，就是如何求多出来的面积，由于已经排好序，我们可以用二分找出大于 $quries[i]$ 的下标来判断哪部分是多出来的。

python代码：
```
class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        n, m = len(nums), len(queries)
        nums.sort()
        sum, ans = [0] * (n + 1), []
        for i in range(1, n + 1):
            sum[i] = sum[i-1] + nums[i-1]
        for q in queries:
            j = bisect_left(nums, q)
            area1 = j * q - sum[j]
            area2 = sum[n] - sum[j] - q * (n - j)
            ans.append(area1 + area2)
        return ans
```
* 时间复杂度： $O(nlogn)$ 
* 空间复杂度： $O(n)$
 
