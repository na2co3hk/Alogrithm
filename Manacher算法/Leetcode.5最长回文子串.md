### 原题链接 -- [[5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)]

### 题目概述：
Tag : 「动态规划」、「Manacher算法」

![image](https://user-images.githubusercontent.com/99656524/196643829-0415e9f7-b822-465f-8aa6-544551afd3fa.png)

### 数据范围
* 1 <= s.length <= 1000
* s 仅由数字和英文字母组成

### 解法一：动态规划
状态表示：第i个字符到第j个字符是否为回文串，若是回文串，返回最大长度
状态转移方程如下：

$$
f[i][j] = f[i+1][j-1]  s[i] == s[j] 
$$

$$
f[i][j] = False  s[i] != s[j]
$$

python代码：
```py
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n, m, begin = len(s), 1, 0 #m为最长的子串的长度,最小长度是1,begin是最长回文子串的起始位置，起始下标为0
        if n < 2:
            return s
        f = [[False] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = True #每个字符单独拿出来都是回文串

        for l in range(2, n + 1): #枚举一下子串长度
            for i in range(n): #枚举左边界
                j = l + i - 1  #右边界
                if j >= n:
                    break  #右边界越界，直接退出循环
                if s[i]!=s[j]: #字符不匹配
                    f[i][j]=False
                else:
                    if j - i < 3: #区间只有2个字符或者1个字符,并且这两个字符时相等的
                        f[i][j] = True
                    else:
                        f[i][j] = f[i+1][j-1]#转移的条件 f[i][j] = f[i+1][j-1] and s[i] == s[j]

                if f[i][j] == True and j - i + 1 > m: #记录最长回文子串,j - i + 1是子串的长度
                    m = j - i + 1
                    begin = i

        return s[begin:begin + m]
```

* 时间复杂度： $O(n^2)$ 动态规划的状态总数为 $O(n^2)$，每次转移 $O(1)$
* 空间复杂度： $O(n^2)$ ，常数级变量

### 解法二：中心扩散法
我们枚举回文串的中心，向两边扩散，返回最大长度
python代码：
```py
class Solution:
    def expend(self, s: str, l: int, r:int):
        n = len(s)
        while l >= 0 and r < n and s[l]==s[r]:
            l -= 1
            r += 1
        return l + 1, r - 1

    def longestPalindrome(self, s: str) -> str:
        n, begin, end = len(s), 0, 0
        for i in range(n):
            odd1, odd2 = self.expend(s, i, i)#记录回文串中心只有一个字符的情况（奇数长度）
            even1, even2 = self.expend(s, i, i+1)#记录回文串中心有两个字符的情况（偶数长度）
            if odd2 - odd1 > end - begin: #更新长度
                begin, end = odd1, odd2
            if even2 - even1 > end - begin:#更新长度
                begin, end = even1, even2
        return s[begin:end+1]
```

* 时间复杂度： $O(n^2)$
* 空间复杂度： $O(1)$ 

### 解法三：Manacher算法
接下来介绍一下本题的终极解法

上面的两总解法，无论是从中心扩散还是动态规划状态转移都需要多次遍历字符串，导致算法时间复杂度非常的高。我们不妨将两种算法的思想结合一下，因此Manacher算法诞生了。

Manacher算法就是结合了中心扩散法和动态规划对最长回文子串求解，步骤和原理如下：

* 首先，由于回文串的长度可能是奇数也有可能是偶数，要分情况来处理太复杂，我们在每个字符间穿插一个字符串中不会出现的字符，常用的是 '#' 和 '!' ，就像这样：#a#b#a# 和 #o#p#p#o#，经过这样的处理，使得所有回文串的长度都变成奇数，然后用数组p[i]记录新字符串的以i为中心的最长半径，这样的处理的好处并不是只有这一个，我们等会再来看
* 其次，我们设定一个最长回文中心 $pos$ 和最长回文半径 $mx$ ，我们可以根据回文串左右对称的性质，对p[i]进行更新。根据回文串对称的性质，第i个位置的元素一定有一个根据回文中心对称的位置j，并且j = 2*pos - i，我们可以根据他的值进行状态转移，但是这样还不够，我们还需要考虑一种情况: 如果以i为中心的回文半径超过了以pos为回文中心的半径mx,那么此时i区间半径是取不到和j区间一样大的半径的,所以我们需要判断是否会发生这种情况,我们在j区间的半径和mx - i（i到半径mx的距离）之间取一个最小值即可。
```cpp
if (i < mx) p[i] = min(p[pos * 2 - i], mx - i);
else p[i] = 1;
```
* 最后，只需要正常遍历字符串进行中心扩散的时候遇到更长的回文串时更新中心和半径即可
* 补充一下长度和起点是怎么算的，设n是以i为回文中心的最长回文子串长度，则其在新字符串中的长度为2n+1。如果一个回文串的长度为偶数，那么该串的回文中心一定是'#'（比如#o#p#p#o#），我们把中间的'#'去掉，剩下的每个字符都能找到一个'#'与其对应，如果一个回文串的长度为奇数，那么该串的回文中心一定是字符（比如#a#b#a#），我们把最左边的'#'去掉，也能找到一个'#''与剩下的每个字符对应，这样就刚好构成了没有添加符号之前的数组的长度，因此我们可以知道2 * p[i] - 1也是新字符串的长度，因此2n+1=2 * p[i]-1化简得到n = p[i]-1。
C++代码：
```cpp
class Solution {
public:
    char ss[2020];//新的字符串
    int cnt, len, ans = 0;
    int p[2*1010];//存储新字符串的以i为中心的最大回文子串长度
    void init(string s)
    {
        len = s.size(),cnt = 1;
        ss[0] = '!'; ss[cnt] = '#';//!#a#b#a#
        for (int i = 0; i < len; i++)
           ss[++cnt] = s[i], ss[++cnt] = '#';
    }
    string longestPalindrome(string s) {
        init(s);
        int pos = 0, mx = 0, start = 0;//回文串的中心，最大半径，起始位置
        for(int i = 1;i <= cnt;i++)
        {
            if (i < mx) p[i] = min(p[pos * 2 - i], mx - i);//根据对称中心得出状态转移方程
            else p[i] = 1; //超过半径了就没有对称了
            while (ss[i + p[i]] == ss[i - p[i]]) p[i]++;//中心扩散
            if (mx < i + p[i]) mx = i + p[i], pos = i;//最大半径更新，回文中心也更新
            if (p[i] - 1 > ans)//保存最大长度和起点
            {
              ans = p[i] - 1;
              start = (i - ans) / 2;
            }
        }
        return s.substr(start,ans);
    }
};
```
* 时间复杂度： $O(n)$
* 空间复杂度： $O(n)$ 

