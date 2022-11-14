//前缀和：存储前n个数的和的数组
//差分：存储相邻两项的差的数组

//前缀和和差分的关系：前缀和与差分互为逆运算

//一维前缀和
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
	//for (int i = 1;i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];//输入时前缀和，数组下标从1开始
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i - 1]; //数组下标从0开始时，i-1相当于和下标做对齐
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

int range(int x1, int y1, int x2, int y2) //求二维区间和[x1,y1](左上角)到[x2,y2](右下角)的前缀和(x1 < x2 and y1 < y2)
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
            //数组下标从0开始时sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i-1][j-1];
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

//-----------------------------------------------------------
//一维差分
#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int n = 5;
vector<int>d(N, 0); //add操作时会超过n+1个数，所以尽量开大点

//给[l,r]区间中的每个数都加上val
void add(int l, int r, int val)
{
	d[l] += val;
	d[r + 1] -= val;
}

int main()
{
	vector<int>nums = { 0, 1, 2, 3, 4, 5 };//数组从下标1开始存储
	for (int i = 1; i <= n; i++)d[i] = nums[i] - nums[i - 1];
	for (int i = 1; i <= n; i++)cout << d[i] << ' ';
	cout << endl;
	add(1, 5, 4);//区间[1,5]的每个数都+3
	for (int i = 1; i <= n; i++)
	{
		nums[i] = d[i] + nums[i - 1]; //前缀和得到原数组
		cout << nums[i] << ' ';
	}
	return 0;
}

//二维差分
#include <bits/stdc++.h>

using namespace std;

const int N = 10100;

int n, m, q;
int nums[N][N], d[N][N];

void add(int x1, int y1, int x2, int y2, int val)
{
    d[x1][y1] += val;
    d[x1][y2 + 1] -= val;
    d[x2 + 1][y1] -= val;
    d[x2 + 1][y2 + 1] += val;
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> nums[i][j];
            add(i, j, i, j, nums[i][j]);
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        add(x1, y1, x2, y2, val);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            nums[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + nums[i-1][j-1]; //二维前缀和
            cout << nums[i][j] << ' ';
        }
        puts("");
    }
    return 0;
}
