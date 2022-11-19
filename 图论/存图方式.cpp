#include<bits/stdc++.h>
#include<cstdlib>
#include<queue>

//邻接表头节点一定要赋值成-1！！！
using namespace std;

const int N = 10010;
int a[N][3] = { {1,5,20}, {1,2,10},{2,4,30}, {4,3,50},{3,2,40} }; //测试用，每个数组第一个数是起点，第二个数是终点，第三个数是权重

//邻接矩阵
int g[N][N];

//邻接表
int h[N], e[N], ne[N], w[N], idx = 0;
void add(int x, int y, int c)//x->y的权重c
{
	e[idx] = y;
	w[idx] = c;
	ne[idx] = h[x];
	h[x] = idx++;	
}

class Edge //类存图
{
	int x; //起点
	int y; //终点
	int c; //权重
	Edge(int x, int y, int c) :x(x), y(y), c(c) {}
};

bool st[N];//检查是否走过这个点

//图的DFS
void dfs(int u) //u为起点
{
	st[u] = true;
	for (int i = h[u]; ~i ; i = ne[i])
	{
		int j = e[i]; //j为终点
		int c = w[i]; //c为x->y的权重
		if (!st[j])dfs(j);
	}
}

int main()
{
	memset(g, 0x3f, sizeof g); //全部初始化为无穷大，代表达不到这个点
	memset(h, -1, sizeof h); //非常重要！！！！！！！
	//邻接矩阵
	for (int i = 0; i < 5; i++)
	{
		int x = a[i][0];
		int y = a[i][1];
		int dist = a[i][2];
		g[x][y] = dist;
	}

	//邻接表
	for (int i = 0; i < 5; i++)add(a[i][0], a[i][1], a[i][2]);
        dfs(a[0][0]);
	
	memset(st, false, sizeof st);
	//图的BFS
	queue<int>q;
	st[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			int c = w[i];
			if (!st[j])
			{
				st[j] = true;
				q.push(j);
			}
		}
	}

	return 0;
}
