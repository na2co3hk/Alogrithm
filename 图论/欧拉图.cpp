#include<bits/stdc++.h>

using namespace std;

//解决“一笔画问题”
//欧拉图都是无相图
using ll = long long;
const int N = 1010;
int n, m;
int p[N], deg[N];//并查集、点的度数

//用并查集判断图是否连通
void init(int n)
{
	for (int i = 1; i <= n; i++)p[i] = i;
}

int find(int x)
{
	if (x == p[x])return x;
	return p[x] = find(p[x]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)p[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
		deg[a]++;
		deg[b]++;
	}

	int beg = p[1], eul = 0, eul_c = 1, cnt = 0; // 分别代表起点， 是否为欧拉路，是否为欧拉回路，度为奇数的点
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] & 1)cnt++; //记录度为奇数的点
		if (p[i] != beg || deg[i] & 1) //如果出现度为奇数的点，则代表没有欧拉回路
		{
			eul_c = 0;
			break;
		}
	}

	if (cnt == 2 || cnt == 0)eul = 1; // 如果度为奇数的点有两个，则代表有欧拉路
	return 0;
}
