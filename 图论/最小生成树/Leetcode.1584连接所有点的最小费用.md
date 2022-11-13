### 原题链接 -- [[1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/)]

### 题目概述：
Tag : 「最小生成树」

![image](https://user-images.githubusercontent.com/99656524/201503569-87e59ce3-8b74-4bb2-ba4e-43f772edbf55.png)

![image](https://user-images.githubusercontent.com/99656524/201503584-03bb37f7-4f5e-4a20-ad72-7b47d529e5e5.png)

![image](https://user-images.githubusercontent.com/99656524/201503592-4f9b34bd-44f0-4315-ac6c-e715242c0aa6.png)

### 解法一：克鲁斯卡尔算法
本题是最小生成树的入门题，可以当作一个模板来看

题目大意为找出链接所有点的最小代价，十分类似于最小生成树的性质，生成树的性质如下：
* 一个连通图可以有多个生成树；
* 一个连通图的所有生成树都包含相同的顶点个数和边数；
* 生成树当中不存在环；
* 移除生成树中的任意一条边都会导致图的不连通， 生成树的边最少特性；
* 在生成树中添加一条边会构成环。
* 对于包含n个顶点的连通图，生成树包含n个顶点和n-1条边；
* 对于包含n个顶点的无向完全图最多包含 $n^n/n^2$ 颗生成树。

而最小生成树，就是在原有的图上给每条边加上权重，查找连接所有点的最小总权重

关于最小生成树，现在我了解到的只有两种算法，我们先来介绍第一种克鲁斯卡尔算法（Kruskal）
克鲁斯卡尔算法的思想类似于贪心

存完图之后，按照每个点的之间的权重从小到大排序，每次取出权重最小的边，将两个点连接起来，这个时候就要用到并查集这种数据结构了

并查集能够判断两个点是否有链接，有判断两个点是否连接和两个点建立连接以及找到该点的祖先等功能

当点的数量 == 边的数量 -1 的时候，说明完成了最小生成树的连接

C++代码：
```cpp
//定义边
class Edge
{
public:
	int start;//起始结点
	int end;//终止结点
	int cost;//权重
	Edge(int start, int end, int cost) :start(start), end(end), cost(cost) {}
};
//并查集
class UnionFind
{
public:
	vector<int>root;
	UnionFind(int n)//有n个数
	{
		root.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
		}
	}

	int find(int x)
	{
		return root[x] == x ? x : root[x]= find(root[x]);
	}

	void Union(int x, int y)
	{
		root[find(x)]=root[find(y)];//根节点连接
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}
};
//Kruskal Algorithm
//链接所有点的最小花费
class Solution
{
public:
	int minCostConnectPoints(vector<vector<int>>points)
	{
		
		int n = points.size();
		vector<Edge>edges;//用于存储边
		UnionFind uf(n);//并查集

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);//计算距离
				Edge edge(i,j,cost);
				edges.emplace_back(edge);
			}
		}
		sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {return a.cost < b.cost; });//按权重从小到大排序
		int res = 0;
		int count = 0;
		for (const auto& edge : edges)
		{
			if (count == n - 1)
			{
				break;//最小生成树的边要比结点少一个
			}
			if (uf.connected(edge.start, edge.end))//若结点间已连接
			{
				continue;
			}
			else
			{
				uf.Union(edge.start, edge.end);
				res += edge.cost;
				count++;
			}
		}
		return res;
	}
};
```
* 时间复杂度： $O(n^2logn)$,一般 Kruskal 是 $O(mlogm)$ 的算法，但本题中 $m=n^2$ 
* 空间复杂度： $O(n^2)$ , $O(n)$ 并查集， $O(n^2)$ 建图
