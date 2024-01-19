// link https://www.codingninjas.com/studio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            else if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = (up + left) % mod;
        }
    }
    return dp[n - 1][m - 1] % mod;
}