### 原题链接 -- [[3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)]

### 题目概述：
Tag : 「滑动窗口」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/196451209-0de334aa-0b75-48d6-a190-e607f265cef0.png)

![image](https://user-images.githubusercontent.com/99656524/196451285-80a12bb3-e870-491b-8475-aeec7a0bab64.png)

### 数据范围
* 0 <= s.length <= 5 * 104
* s 由英文字母、数字、符号和空格组成

### 解法一：哈希表
先遍历数组，将遍历的每个字母放到哈希表中，如果遇到重复的，就回到字母上一次出现的位置的下一个位置，并清空哈希表重新开始计数，更新 $ans$

这个是我一开始做的答案，因为要不断的回到重复字母的上一个位置，所以时间复杂度非常高，执行用时达到了762ms
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==1)return 1;
        int count = 0;
        int res = 0;
        unordered_map<int,int>hash;
        for(int i = 0;i<n;i++)
        {
            if(hash.find(s[i])!=hash.end())//有重复
            {
                res = max(count,res);
                i = hash[s[i]]+1;//回溯
                count = 0;
                hash.clear();
            }
            hash[s[i]] = i;//哈希表存字符上一次出现的位置
            count++;
            
        }
        return max(count,res);//如果字符一直没有重复，count就不会归0
    }
};
```
* 时间复杂度： $O(n^2)$ 
* 空间复杂度： $O(n)$ 

### 解法二：哈希表 + 滑动窗口
解法一用时过高是因为遇到重复字母需要不断地回到上一个位置，重复遍历的字母太多了。而这个过程可以用双指针优化，右指针不断地扩张，当不符合条件的时候（本题指遇到重复的字母）左指针向右扩张，这样我们只需要遍历一遍数组即可求出无重复字符的最长字串
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){ //右指针扩张
            while (lookup.find(s[i]) != lookup.end()){ //发现重复
                lookup.erase(s[left]); //从哈希表中移除
                left ++; //左指针向右扩张
            }
            maxStr = max(maxStr,i-left+1); //统计最大长度
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};
```

最后附赠一下滑动窗口模板（python版本）
```py
//模板
def findSubArray(nums):
    N = len(nums) # 数组/字符串长度
    left, right = 0, 0 # 双指针，表示当前遍历的区间[left, right]，闭区间
    sums = 0 # 用于统计 子数组/子区间 是否有效，根据题目可能会改成求和/计数
    res = 0 # 保存最大的满足题目要求的 子数组/子串 长度
    while right < N: # 当右边的指针没有搜索到 数组/字符串 的结尾
        sums += nums[right] # 增加当前右边指针的数字/字符的求和/计数
        while 区间[left, right]不符合题意: # 此时需要一直移动左指针，直至找到一个符合题意的区间
            sums -= nums[left] # 移动左指针前需要从counter中减少left位置字符的求和/计数
            left += 1 # 真正的移动左指针，注意不能跟上面一行代码写反
        # 到 while 结束时，我们找到了一个符合题意要求的 子数组/子串
        res = max(res, right - left + 1) # 需要更新结果
        right += 1 # 移动右指针，去探索新的区间
    return res
```
