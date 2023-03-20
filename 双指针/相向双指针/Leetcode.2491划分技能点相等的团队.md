### 原题链接 -- [[2491. 划分技能点相等的团队](https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill/)]

### 题目概述：
Tag : 「双指针」、「哈希表」、「排序」

![image](https://user-images.githubusercontent.com/99656524/226381707-fb71093b-9337-44da-b0f9-60ca63ae117a.png)

![image](https://user-images.githubusercontent.com/99656524/226381769-598b031f-72a0-4f3b-8765-61a5bbd578d5.png)

### 数据范围
* $2 <= skill.length <= 10^5$
* $skill.length 是偶数$
* $1 <= skill[i] <= 1000$

### 解法一：排序 + 双指针
题目大意为将n个人分为 n/2 个2人小组，要求他们的技能点相同。而要想要技能点和相同，并且刚好分成n/2对，最好的办法就是"一大带一小"，这样才能使每组的技能点和相同。我们先对数组排序，
然后再用双指针取一头一尾，加起来，并用哈希表记下是否刚好为n/2对。

$排序是一种很强的性质，当答案不需要考虑顺序问题时，优先考虑排序$

C++代码:
```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int m = n >> 1;
        sort(skill.begin(), skill.end());
        int l = 0, r = n - 1, rec = 0;
        unordered_map<long long, int>hash;
        long long res = 0;
        while(l <= r)
        {
            hash[skill[l] + skill[r]]++;
            rec = hash[skill[l] + skill[r]];
            res += skill[l]*skill[r];
            l++;
            r--;
        }
        return rec == m ? res : -1;
    }
};
```
* 时间复杂度： $O(nlogn)$
* 空间复杂度： $O(n)$，用到哈希表

### 更好的写法
其实不需要哈希表，直接用变量记下即可，甚至也不需要双指针，直接枚举n/2对，代码来源[灵茶山艾府](https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill/solution/pai-xu-hou-zui-xiao-zui-da-pi-pei-by-end-7sta/)

python代码：
```py
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        ans, s = 0, skill[0] + skill[-1]
        for i in range(len(skill) // 2):
            x, y = skill[i], skill[-1 - i]
            if x + y != s: return -1
            ans += x * y
        return ans
```
* 时间复杂度： $O(nlogn)$
* 空间复杂度： $O(1)$，用到哈希表
