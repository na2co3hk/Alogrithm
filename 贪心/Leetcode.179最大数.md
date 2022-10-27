### 原题链接 -- [[179. 最大数](https://leetcode.cn/problems/largest-number/)]

### 题目概述：
Tag : 「贪心」、「排序」

![image](https://user-images.githubusercontent.com/99656524/198170612-b9c77b27-818c-4c04-8538-455554e7df9a.png)

### 数据范围
* $1 <= nums.length <= 100$
* $0 <= nums[i] <= 10^9$

### 解法一：贪心
本题的大意为用已有的数字组合成一个最大的数字，要想组合成一个最大的数字，就要先将数字从大到小排序，但是并不是普通排序，我们需要判断两个数拼接之后的数进行比较，比如 12 和 345，34512 > 12345 ，所以我们将345放在前面，以此类推

C++代码：
```cpp
class Solution {
private:
    static bool cmp(const int& a, const int& b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        for (int& t : nums) {
            ans += to_string(t);
        }
        if (ans[0] == '0') {  // 不能是00000
            return "0";
        }
        return ans;
    }
};
```
* 时间复杂度： $O(nlognlogm)$ 
* 空间复杂度： $O(nlogn)$， 
