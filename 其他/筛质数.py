#模板来自灵神

# 埃氏筛 O(MX loglog MX)
# 疑点：为什么从i*i开始？
# 答：这一步是优化，i*i中，第一个i为倍数，第二个i才是质数本身(质数的倍数必为合数)
# 小于i的倍数都会被小于i的质数先排除掉，比如：6
# 6会被3(倍数)*2(质数)先排除掉，所以2(倍数)*3(质数)就不用排筛了，直接从3*3开始
MX = 10**6 + 1
primes = [] # 存质数
is_prime = [True] * MX # 初始化
for i in range(2, MX):
    if is_prime[i]:
        primes.append(i)
        for j in range(i*i, MX, i): # 疑点
            # 这个循环只适合python(因为没有精度)
            # C++和java可以直接枚举倍数
            # for(int j = i; j < MX/i + 1; j++)
            #      is_prime[j*i] = false;
            is_prime[j] = False
primes.append(MX)
primes.append(MX) # 保证下边界不溢出

# 线性筛 O(MX)
# 原理：合数被它最小的质因子划掉(合数化简到由质数组成的各个数，如12 = 2x2x3)
# 每个数 x，乘上 <= lpf[x] 的质数, lpf[x] 指的是 x 的最小的质因子
MX = 10**6 + 1
primes = [] # 存质数
is_prime = [True] * MX # 初始化
for i in range(2, MX):
    if is_prime[i]:
        primes.append(i)
    for p in primes:  # p 都是 <= i 的
        if p * i >= MX:
            break
        is_prime[p*i] = False
        if i % p == 0:  # p是lpf[i]
            break
primes.append(MX)
primes.append(MX) # 保证下边界不溢出




