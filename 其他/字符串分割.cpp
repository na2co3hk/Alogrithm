#include <bits/stdc++.h>

using namespace std;
//返回值:字符数组 split(s:待分割字符, c:分割标志)
vector<string> split(const string& s, const string& c) {
	size_t pos1, pos2;
	vector<string>v;
	pos2 = s.find(c);
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
