//初始化：
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

//有更新，新加一条x到y的边权重为w（下标随题目的点是否包含0而定）
for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
              d[i][j] = min(d[i][j], d[i][x] + w + d[y][j]);
