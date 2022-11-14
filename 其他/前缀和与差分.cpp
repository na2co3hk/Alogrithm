//前缀和：存储前n个数的和的数组
#include<bits/stdc++.h>

using namespace std;

int n = 5;
//前缀和初始化
vector<int>sum(n + 1, 0);

int range(int l, int r) //前缀和求区间和[l,r]
{
	return sum[r] - sum[l - 1];
}

int main()
{
	vector<int>nums = { 1, 2, 3, 4, 5 };
	//前缀和输入
	//for (int i = 1;i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];//输入时前缀和
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i - 1]; //下标从1开始
	for (auto x : sum)cout << x << ' ';
	cout << endl;
	cout << range(1, 5); //[1,5]的区间和
	return 0;
}

//-----------------------------------------------------------
//二维前缀和
#include <bits/stdc++.h>

using namespace std;
const int N = 1010;

int n, m, q;

int a[N][N], sum[N][N];

int range(int x1, int y1, int x2, int y2) //求二维区间和[x1,y1]到[x2,y2]的前缀和(x1 < x2 and y1 < y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main() 
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
	{
            cin >> a[i][j];
            //二维前缀和输入
            //非输入时sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i-1][j-1];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j]; 
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << range(x1, y1, x2, y2) << endl;
    }
    return 0;
}
