### 原题链接 -- [1125. 最小的必要团队](https://leetcode.cn/problems/smallest-sufficient-team/)]

### 题目概述：
Tag : 「状态压缩」、「动态规划」

![image](https://user-images.githubusercontent.com/99656524/230697419-445890fd-b247-4ba2-a7bd-e96067662d21.png)

### 数据范围
* 1 <= req_skills.length <= 16
* 1 <= req_skills[i].length <= 16
* req_skills[i] 由小写英文字母组成
* req_skills 中的所有字符串 互不相同
* 1 <= people.length <= 60
* 0 <= people[i].length <= 16
* 1 <= people[i][j].length <= 16
* people[i][j] 由小写英文字母组成
* people[i] 中的所有字符串 互不相同
* people[i] 中的每个技能是 req_skills 中的技能
* 题目数据保证「必要团队」一定存在

### 解法一：动态规划 + 状态压缩
参考了灵神[题解](https://leetcode.cn/problems/smallest-sufficient-team/solution/zhuang-ya-0-1-bei-bao-cha-biao-fa-vs-shu-qode/)，以下是个人的一点理解

由于 $people$ 中的每个下标只有选和不选两种状态，并且数据范围并不算大，可以考虑用二进制枚举每种状态。先将每项技能在 $req_skills$ 的下标映射，然后用二进制集合保存每个人会的技能，比如示例中，一个人会 "java" 和 "nodejs" 的二进制集合表示为110。

和01背包问题一样，接下来就是枚举每种状态求出最优解，f[i][j]状态表示为 表示从前i个集合中选择一些集合，并集等于j，至少需要选择的集合个数。

C++代码：
```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        unordered_map<string, int> sid;
        int m = req_skills.size();
        for (int i = 0; i < m; ++i)
            sid[req_skills[i]] = i; // 字符串映射到下标

        int n = people.size(), u = 1 << m;
        // f[i+1][j] 表示从前 i 个集合中选择一些集合，并集等于 j，需要选择的最小集合
        long long f[n + 1][u];
        fill(f[0], f[0] + u, (1LL << n) - 1); // 对应记忆化搜索中的 if (i < 0) return all;
        f[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (auto &s: people[i]) // 把 people[i] 压缩成一个二进制数 mask[i]
                mask |= 1 << sid[s];
            f[i + 1][0] = 0;
            for (int j = 1; j < u; ++j) {
                auto r1 = f[i][j]; // 不选 mask
                auto r2 = f[i][j & ~mask] | (1L << i); // 选 mask (f[i][j]也是一个mask，代表要选哪些人组成答案，在后面res统计的时候有用)
                f[i + 1][j] = __builtin_popcountll(r1) < __builtin_popcountll(r2) ? r1 : r2; //相当于统计bit_count，集合中1的个数
            }
        }
        auto res = f[n][u - 1];

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if ((res >> i) & 1)
                ans.push_back(i); // 所有在 res 中的下标
        return ans;
    }
};
```
* 时间复杂度： $O(T + n * 2^m)$ ，其中 T 为 people中的字符串的长度和，n为people的长度，m为req_Skills的长度
* 空间复杂度： $O(S + n * 2^m)$ ，其中 S为req_Skills中字符串长度之和
