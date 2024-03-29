//快速幂（原理是幂模拟二进制）
//如果是用于费马定理a*a^(p-2) = 1(mod p)，p一定要是质数
求 m^k mod p，时间复杂度 O(logk)。
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)//k不为0
    {
        if (k&1) res = res * t % p;//如果爆int，就强制转换long long int
        t = t * t % p;//t变t的平方
        k >>= 1;
    }
    return res;
}

//递归写法
long qmi(long x, int n)
{
	if (n == 0)return 1;
	if (n & 1)return x*qmi(x * x, n >> 1);
	else return qmi(x * x, n >> 1);
}

//快速乘（倍增的思想）
long mul(long a, long k) {//可以改成int
    long ans = 0;
    while (k > 0) {
        if ((k & 1) == 1) ans += a;
        k >>= 1;
        a += a;
    }
    return ans;
}

//矩阵快速幂，用于求一个矩阵m的n次方（O(logn)）
using i64 = long long;
using matrix = vector<vector<int>>;
matrix mul(matrix a, matrix b)
{
   int n = a.size();
   int m = b.size();
   int t = a[0].size();
   matrix c(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < m; j++)
       {
	   for (int k = 0; k < t; k++)
	   {
	       c[i][j] += a[i][k] * b[k][j];
	   }
       }
   }
   return c;
}

matrix pow(matrix a, int n)
{
   matrix res = { {1, 0}, {0, 1} }; //n阶对角矩阵
   while (n)
   {
       if (n & 1)res = mul(res, a);
       a = mul(a, a);
       n >>= 1;
   }
   return res;
}
