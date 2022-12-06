#include<iostream>
#include<stack>

using namespace std;

const int N = 1010;
int g[N][N], dist[N], path[N];
bool st[N];
int n, m;
void print(int u);

void dijkstra(int u)
{
	memset(dist, 0x3f, sizeof dist);
	dist[u] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = -1;
		for (int y = 1; y <= n; y++)
		{
			if (!st[y] && (x == -1 || dist[x] > dist[y]))x = y;
		}
		st[x] = true;
		for (int y = 1; y <= n; y++)
		{
			if (!st[y] && dist[y] > dist[x] + g[x][y])
			{
				dist[y] = dist[x] + g[x][y];
				path[y] = x; //统计经过路径
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 0x3f3f3f3f)dist[i] = -1;
	}
	print(u);
	return;
}

void print(int u)
{
	stack<int>stk;
	for (int i = 1; i <= n; i++)
	{
		int p = i;
		while (path[p] != -1)
		{
			stk.push(p); //将路径放入栈中
			p = path[p];
		}
		cout << u << "-->" << i << ' ';
		cout << "dist = " << dist[i] << ' ';
		cout << u;
		while (!stk.empty()) //一个个弹出代表正序路径
		{
			cout << "-->" << stk.top();
			stk.pop();
		}
		cout << endl;
	}
}

int main()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		g[x][y] = min(g[x][y], c);
	}
	for (int i = 0; i <= n; i++)path[i] = -1;
	//输入起源点
	dijkstra(1);
	return 0;
}
