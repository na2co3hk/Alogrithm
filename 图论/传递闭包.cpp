#include<bits/stdc++.h>

using namespace std;

//作用于邻接矩阵
//判断图是否连通（任意一个点出发能到达图中所有点）
using ll = long long;
const int N = 1010;
int n, ans = 0;
char s[N];
bitset<N>a[N]; // 用于存储邻接矩阵

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)a[i][j] = s[j] - '0';
		a[i][i] = 1;//若有要求自反性(自己到自己也算一条边)
	}
	
	//warshall算法
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i].test(i))a[j] |= a[i]; //相当于a[i][j] == 1
		}
	}

	for (int i = 0; i < n; i++)ans += a[i].count(); //统计1的个数
	cout << ans;
	return 0;
}
