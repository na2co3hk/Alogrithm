### 原题链接 -- [[3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)]

### 题目概述：
Tag : 「滑动窗口」

![image](https://user-images.githubusercontent.com/99656524/201590755-40bff27c-ad78-4b3d-a6d1-d646745c5809.png)

### 数据范围
* 0 <= s.length <= 5 * 10^4
* s 由英文字母、数字、符号和空格组成

### 解法一：滑动窗口
根据题目大意，我们需要找到一个没有重复的最长连续区间，看到没有重复这样的字样，我们可以考虑用集合去重，最长连续区间我们可以考虑用双指针中的滑动窗口去做。滑动窗口的的过程就是一个指针不断向右移动，若遇到不满足条件（这里是出现重复字符）的时候，就移动左指针缩小区间，最后统计最大长度。

python代码：
```py
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = left = 0
        cnt = Counter() #其他语言可以用map记录出现次数
        for right, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:  # 不满足要求
                cnt[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$
