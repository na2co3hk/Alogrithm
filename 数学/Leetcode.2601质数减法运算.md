### 原题链接 -- [[2601. 质数减法运算](https://leetcode.cn/problems/prime-subtraction-operation/)]

### 题目概述：
Tag : 「数学」、「二分查找」

![image](https://user-images.githubusercontent.com/99656524/230751038-fe1ae375-0462-4f9a-ba09-e477963c9bad.png)

![image](https://user-images.githubusercontent.com/99656524/230751045-5bfaa0e2-bf13-42d7-bdc3-5d1c58dcd5b5.png)

### 数据范围
* 1 <= nums.length <= 1000
* 1 <= nums[i] <= 1000
* nums.length == n

### 解法一：二分查找 + 筛质数
题目大意为将数组元素某些元素减去小于它的一个质数后使数组严格递增。题目给的最大数据为1000，我们可以枚举1000范围内的质数并将他们存到数组中，这样做有两个好处，第一个是质数的存放结构是有序的，可以使用二分查找来找到小于某个数的最大质数，第二是这一步可以通过预处理来解决，不用参与到运算中。需要注意的是，这题还有一点贪心的思想，体现在我们其实不用找到数组中哪些数需要进行操作，而是将数组全部元素都进行操作，也就是将数组全部元素减去小于它本身，并且大于前一个元素的质数（若不大于前一个元素，就有可能出现减完质数后比前一个数还小的情况）。

筛质数是灵神的模板

python代码：
```python
MX = 1010
primes = [0] # 存质数 0是哨兵，避免二分越界
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
primes.append(MX)
            
class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        n, p = len(nums), 0
        for c in nums:
            if c <= p:
                return False
            p = c - primes[bisect_left(primes, c - p) - 1]
        return True
```
* 时间复杂度： $O(nlogMX)$ ，其中n是nums的长度 
* 空间复杂度： $O(1)$ 
