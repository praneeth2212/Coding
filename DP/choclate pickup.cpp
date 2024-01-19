
// https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
int maximumChocolates(int r, int c, vector<vector<int>> &g)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                dp[r - 1][j1][j2] = g[r - 1][j1];
            }
            else
            {
                dp[r - 1][j1][j2] = g[r - 1][j1] + g[r - 1][j2];
            }
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = g[i][j1];
                        }
                        else
                        {
                            value = g[i][j1] + g[i][j2];
                        }
                        if ((j1 + d1 >= 0 && j1 + d1 < c) && (j2 + d1 >= 0 && j2 + d2 < c))
                        {
                            value += dp[i + 1][j1 + d1][j2 + d2];
                        }
                        else
                        {
                            value += -1e8;
                        }
                        maxi = max(maxi, value);
                        dp[i][j1][j2] = maxi;
                    }
                }
            }
        }
    }
    return dp[0][0][c - 1];
}