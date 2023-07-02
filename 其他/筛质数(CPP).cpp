//模板来自灵神

//线性筛
const int MX = 1e6;
vector<int> primes;

int init = []() {
    bool np[MX + 1]{};
    for (int i = 2; i <= MX; ++i)
        if (!np[i]) {
            primes.push_back(i);
            for (int j = i; j <= MX / i; ++j) // 避免溢出的写法
                np[i * j] = true;
        }
    primes.push_back(MX + 1);
    primes.push_back(MX + 1); // 保证下面下标不会越界
    return 0;
}();

作者：灵茶山艾府
链接：https://leetcode.cn/problems/closest-prime-numbers-in-range/solutions/2040087/yu-chu-li-zhi-shu-mei-ju-by-endlesscheng-uw2b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//埃氏筛
  const int MX = 1e6;
vector<int> primes;

int init = []() {
    bool np[MX + 1]{};
    for (int i = 2; i <= MX; ++i) {
        if (!np[i]) primes.push_back(i);
        for (int p: primes) {
            if (i * p > MX) break;
            np[i * p] = true;
            if (i % p == 0) break;
        }
    }
    primes.push_back(MX + 1);
    primes.push_back(MX + 1); // 保证下面下标不会越界
    return 0;
}();

作者：灵茶山艾府
链接：https://leetcode.cn/problems/closest-prime-numbers-in-range/solutions/2040087/yu-chu-li-zhi-shu-mei-ju-by-endlesscheng-uw2b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
