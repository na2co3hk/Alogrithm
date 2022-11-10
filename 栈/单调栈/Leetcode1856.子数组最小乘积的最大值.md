### 原题链接 -- [[1856. 子数组最小乘积的最大值](https://leetcode.cn/problems/maximum-subarray-min-product/)]

### 题目概述：
Tag : 「单调栈」、「计算贡献」

![image](https://user-images.githubusercontent.com/99656524/201104196-80ac92c5-8a51-4817-8274-88068c452d13.png)

### 提示
* $1 <= nums.length <= 10^5$
* $1 <= nums[i] <= 10^7$

### 解法一：单调栈
题目大意为寻找一个区间的最小值乘以区间和最大的数，看到最小值，且连续区间，基本可以考虑是单调栈了，并且还需要区间和，我们可以用前缀和来做。最后枚举每个数为最小值，计算最大的贡献

注意：题目要求为64位整数，所以要返回值要改为long long

C++代码：
```cpp
const int MOD = 1e9 + 7;

const auto ios_sync_off = []() { //优化输入输出时间
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
     using int64 = long long;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int64>pre(n + 1, 0);
	    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + nums[i - 1];
        vector<int>left(n);
	    vector<int>right(n,n-1);
	    stack<int>stk;
	    for (int i = 0; i < n; i++) {
		   while (!stk.empty() && nums[stk.top()] >= nums[i])
		   {
			right[stk.top()] = i - 1;
			stk.pop();
		   }
		if (!stk.empty())left[i] = stk.top() + 1;
		stk.push(i);
	    }
        int64 ans = 0;
	    for (int i = 0; i < n; i++) {
		int l = left[i];
		int r = right[i];
		int64 tot = (pre[r+1] - pre[l]);
		ans = max(ans ,tot*nums[i]);
	    }
        return ans % MOD;
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ ,使用栈
