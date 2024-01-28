
// link https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
long solve(vector<int> &d, int i, int v, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (v % d[0] == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][v] != -1)
    {
        return dp[i][v];
    }
    int nottake = solve(d, i - 1, v, dp);
    int take = 0;
    if (d[i] <= v)
        take = solve(d, i, v - d[i], dp);
    return dp[i][v] = take + nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<long> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = denominations[i];
    }
    vector<vector<long>> dp(n, (vector<long>(value + 1, 0)));
    for (int i = 0; i <= value; i++)
    {
        if (i % d[0] == 0)
            dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            long nottake = dp[i - 1][j];
            long take = 0;
            if (d[i] <= j)
            {
                take = dp[i][j - d[i]];
            }
            dp[i][j] = take + nottake;
        }
    }
    return dp[n - 1][value];
}