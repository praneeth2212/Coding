
// link https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, (vector<int>(m, 0)));
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + dp[i - 1][j];
            int ld = matrix[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld += -1e9;
            int rd = matrix[i][j];
            if (j + 1 < m)
                rd += dp[i - 1][j + 1];
            else
                rd += -1e9;
            dp[i][j] = max(u, max(ld, rd));
        }
    }
    int maxi = -1e9;
    for (int k = 0; k < m; k++)
    {
        maxi = max(maxi, dp[n - 1][k]);
    }
    return maxi;
}