
// link https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
int solve(vector<int> &w, vector<int> &v, int i, int mw, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (w[i] <= mw)
        {
            return v[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[i][mw] != -1)
    {
        return dp[i][mw];
    }
    int nottake = solve(w, v, i - 1, mw, dp);
    int take = INT_MIN;
    if (w[i] <= mw)
    {
        take = v[i] + solve(w, v, i - 1, mw - w[i], dp);
    }
    return dp[i][mw] = max(take, nottake);
}
int knapsack(vector<int> w, vector<int> v, int n, int mw)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(mw + 1, 0));
    for (int i = w[0]; i <= mw; i++)
        dp[0][i] = v[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= mw; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            if (w[i] <= j)
            {
                take = v[i] + dp[i - 1][j - w[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][mw];
}