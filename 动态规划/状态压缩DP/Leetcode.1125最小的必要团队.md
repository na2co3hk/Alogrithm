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
