### 原题链接 -- [[1092. 最短公共超序列](https://leetcode.cn/problems/shortest-common-supersequence/)]

### 题目概述：
Tag : 「动态规划」、「双指针」

![image](https://user-images.githubusercontent.com/99656524/228400606-6168d64b-6c82-4a81-b8ab-dd1b17eb9ed4.png)

### 数据范围
* 1 <= str1.length, str2.length <= 1000
* str1 和 str2 都由小写英文字母组成。

### 解法一：动态规划 + 双指针
根据题目，不难想到和[最长公共子序列（LCS）](https://github.com/na2co3hk/Alogrithm/blob/main/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/LCS/Leetcode.1143%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.md)有关。并且，公共超序列是由三部分组成的，第一部分为两个字符串的最长公共子序列（如果不包含LCS的话就不能称之为公共超序列了），剩下两部分为s1或s2特有的部分（如题目示例的案例中，'c'由s2提供，"ab"为LCS，'ac'由s1提供）。因此，我们需要先构造出LCS的动态规划数组，然后再用两个指针分别指向两个字符串的尾部往前扫（为什么是指向尾部往前扫？求最优方案时，从前往后递推时没有方向性的，因为不知道转移到哪个方向才是正确的，比如"ab", "bd"，f(1,0), f(0,1)都是0，你此时无法确定这个最优解要怎么走，而从后往前递推才是求解最优解的过程，这也和DP的无后效性有关），若两个指针中有一个扫到尾（0下标）了，就将另一个字符串的所有字符添加到答案中。若两个指针指向的字符相等，则代表为LCS的那部分，若 $f[i][j] == f[i][j-1]$ 则代表最优解是不选s1[i]而选s2[j]，将s2添加到答案中，这代表的是s2特有的部分，  $f[i][j] == f[i-1][j]$ 同理，代表s1特有的部分，这样答案出来了，最后由于是逆序添加的字符，还需要将答案反转一下。

C++代码：
```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>>f(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n;i++)
        {
            for(int j = 1;j <= m ;j++)
            {
                f[i][j] = max(f[i-1][j], f[i][j - 1]);
                if(str1[i-1] == str2[j-1])f[i][j] = f[i-1][j-1] + 1;
            }
        }

        string ans;
        int i = n, j = m;
        while(i || j)
        {
            if(i == 0)ans += str2[--j];
            else if(j == 0)ans += str1[--i];
            else
            {
                if(str1[i-1] == str2[j-1])ans += str1[--i],--j;
                else if(f[i][j] == f[i-1][j])ans += str1[--i];
                else if(f[i][j] == f[i][j-1])ans += str2[--j];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
* 时间复杂度： $O(nm)$ 
* 空间复杂度： $O(nm)$ 

