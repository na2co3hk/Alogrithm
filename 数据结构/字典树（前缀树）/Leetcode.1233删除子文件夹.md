### 原题链接 -- [[1233. 删除子文件夹](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/)]

### 题目概述：
Tag : 「字典树」、「哈希表」

![image](https://user-images.githubusercontent.com/99656524/217706277-02c3329b-209a-458c-95f2-8d4c2a558cff.png)

### 数据范围
* $1 <= folder.length <= 4 * 10^4$
* $2 <= folder[i].length <= 100$
* folder[i] 只包含小写字母和 '/'
* folder[i] 总是以字符 '/' 起始
* 每个文件夹名都是 唯一 的

### 解法一：字典树
题目大意为删除所有子文件，即只保留最短前缀路径。我们用一个哈希表来存每个
