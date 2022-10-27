### 原题链接 -- [[Death's Blessing](https://codeforces.com/problemset/problem/1749/B)]

### 题目概述：
Tag : 「贪心」

![image](https://user-images.githubusercontent.com/99656524/198173590-e45a7a81-b4c4-4d54-b303-7d41dac82da7.png)

![image](https://user-images.githubusercontent.com/99656524/198173642-0a291461-5f83-4752-b939-86b3d88aeee9.png)

### 解法一：贪心
题目大意为每个怪物死亡后都会给两边的队友加 b[i] 的生命值（在两边的怪物只会给一边加BUFF），我们需要在最短时间内击杀所有怪物。根据题意，我们要击杀所有怪物，就必须会用到每个怪物基础生命值和(sum)的时间，不然我们也没法击杀所有怪物，然后才需要考虑死亡祝福。由于在两边的怪物只会给一边加BUFF，我们可以从两边开始击杀，要在最短时间内击杀，我们就必须要留意死亡祝福能力最强的人，因为要是给他施展了祝福就必然不是最短时间（比如一个怪物生命值是1，死亡祝福是10000000，死亡后给队友的BUFF太离谱了），所以我们将最后击杀这个死亡祝福能力最强的怪物，这样就完成了题目要求

C++代码：
```cpp
#include<bits/stdc++.h>

using ll = long long;

using namespace std;

void solve()
{
	int a;
	cin >> a;
	vector<ll>h(a);
	vector<ll>b(a);
	for (int i = 0; i < a; i++)cin >> h[i];
	for (int i = 0; i < a; i++)cin >> b[i];
	auto ans = accumulate(h.begin(), h.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
	ans -= *max_element(b.begin(), b.end());
	cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}
	return 0;
}
```
* 时间复杂度： $O(n*a^2)$ 
* 空间复杂度： $O(1)$ 
