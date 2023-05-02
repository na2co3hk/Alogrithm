#include <bits/stdc++.h>

using namespace std;
//返回值:字符数组 split(s:待分割字符, c:分割标志)
vector<string> split(const string& s, const string& c) {
	size_t pos1, pos2;
	vector<string>v;
	pos2 = s.find(c); //可以根据KMP手写
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())v.push_back(s.substr(pos1));
	return v;
}

//split(s:待分割字符, v:传出字符数组, c:分割标志)
void split(const string& s, vector<string>& v, const string& c) {
	size_t pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())v.push_back(s.substr(pos1));
}

//KMP算法
//找出第一个匹配字串的下标
//通过记录已经匹配的前缀加速下一次的匹配
//https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/
int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 1,j = 1;
        //创建next数组
        vector<int>next(m+1);
        //初始化next数组
        for(i = 1,j = 0;i<m;i++)
        {
            
            while(j && needle[i]!=needle[j])
            {
                j = next[j-1];
            }
            if(needle[i]==needle[j])
            {
                next[i]=++j;
            }
            else
            {
                next[i]=0;
            }
        }

        //字符串匹配
        for(i = 0, j = 0;i<n;i++)
        {
            while(j && haystack[i]!=needle[j])
            {
                j = next[j-1];
            }
            if(haystack[i]==needle[j])
            {
                j++;
            }
            if(j==m)return i-m+1;
        }
        return -1;
}
