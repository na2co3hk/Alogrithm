/* 将并查集分为两类
- p[1，...i - 1, i, i + 1…N]代表数字属于第一类:p[i]维护的是和编号i非敌人的编号的父节点，
- p[N + 1…...i - 1 + N, i + N, i + 1 + N…2*N]代表数字属于第二类，p[i + N]维护的是和编号i为敌人的编号的父节点。
*/

#include<iostream>
#include<vector>
using namespace std;

//用于刷题的模板
//核心代码极短模板
int r[N];

int find(int x)
{
   if (r[x] != x) r[x] = find(r[x]);
   return r[x];
}

bool connected(int x, int y)//检查是否相连
{
   return find(x) == find(y);
}

void Union(int x, int y)
{
   r[find(x)] = r[find(y)];//根节点
}

//按秩合并极短模板
void Union(int x,int y){
  int rx=find(x);
  int ry=find(y);
  if(rx!=ry){
      if(rk[rx]<rk[ry])   r[rx]=ry;
      else  if(rk[ry]<rk[rx])  r[ry]=rx;
      else r[rx]=ry,rk[ry]++;
  }
}

//接下来是各种版本的并查集
//并查集快速查找
class UnionFind1
{
	vector<int>root;//数组内容存放当前索引的根节点
	UnionFind1(int n)//有n个数
	{
		root.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
		}
	}

	int find(int x)
	{
		return root[x];//查找根节点的索引
	}

	void Union(int x, int y)//合并
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)//根节点不相同
		{
			for (int i = 0; i < root.size(); i++)//遍历数组，找到根节点和Y相同的值
			{
				if (root[i] == rootY)
				{
					root[i] = rootX;//把他们改成X的根节点
				}
			}
		}
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}
};

//并查集快速合并
class UnionFind2
{
	vector<int>root;//数组内容存放当前索引的根节点
	UnionFind2(int n)//有n个数
	{
		root.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
		}
	}

	int find(int x)
	{
		while (x != root[x])
		{
			x = root[x];//通过父节点找到根节点
		}
		return x;
	}

	void Union(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)
		{
			root[rootY] = rootX;//Y的根节点合并到X的根节点
		}
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}
};

//按秩合并的并查集（针对于快速合并的优化）
class UnionFind3
{
	vector<int>root;//数组内容存放当前索引的根节点
	vector<int>rank;//记录树的高度

	UnionFind3(int n)//有n个数
	{
		root.assign(n, 0);
		rank.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
			rank[i] = 1;//每个结点的初始高度都为1
		}
	}

	int find(int x)
	{
		while (x != root[x])
		{
			x = root[x];//通过父节点找到根节点
		}
		return x;
	}

	void Union(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)
		{
			if (rank[rootX] > rank[rootY])//如果X的根结点的高度大于Y根结点的高度
			{
				root[rootY] = rootX;//Y的根节点合并到X的根节点
			}
			else if (rank[rootX] < rank[rootY])
			{
				root[rootX] = rootY;//反之
			}
			else//根节点高度相同
			{
				root[rootY] = rootX;//和之前一样
				root[rootX] += 1;
			}
		}
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}

};

//路径压缩的并查集（针对于快速合并的优化）
class UnionFind4
{
	vector<int>root;//数组内容存放当前索引的根节点
	UnionFind4(int n)//有n个数
	{
		root.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
		}
	}

	int find(int x)
	{
		if (x == root[x])//将父结点和子结点直接链接，压缩路径
		{
			return x;
		}
		return find(root[x]);
	}

	void Union(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)
		{
			root[rootY] = rootX;//Y的根节点合并到X的根节点
		}
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}
};

//究极综合并查集
class UnionFind
{
	vector<int>root;
	vector<int>rank;
	UnionFind(int n)//有n个数
	{
		root.assign(n, 0);
		rank.assign(n, 0);
		for (int i = 0; i < n; i++)//初始化
		{
			root[i] = i;
			rank[i] = 1;//每个结点的初始高度都为1
		}
	}

	int find(int x)
	{
		if (x == root[x])//将父结点和子结点直接链接，压缩路径
		{
			return x;
		}
		return find(root[x]);
	}

	void Union(int x, int y)
	{
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY)
		{
			if (rank[rootX] > rank[rootY])//如果X的根结点的高度大于Y根结点的高度
			{
				root[rootY] = rootX;//Y的根节点合并到X的根节点
			}
			else if (rank[rootX] < rank[rootY])
			{
				root[rootX] = rootY;//反之
			}
			else//根节点高度相同
			{
				root[rootY] = rootX;//和之前一样
				rank[rootX] += 1;
			}
		}
	}

	bool connected(int x, int y)//检查是否相连
	{
		return find(x) == find(y);
	}
};

//究极快速并且代码量少的并查集模板
class UnionFind
{
public:
	vector<int>root;
	UnionFind(int n)//有n个数
	{
		root.assign(n, 0);	
		for (int i = 0; i < n; i++)root[i] = i;
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
