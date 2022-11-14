//前缀和：存储前n个数的和的数组
for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i - 1];
