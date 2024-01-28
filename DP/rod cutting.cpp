

// link https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
int solve(int i, vector<int> &price, int n)
{
    if (i == 0)
    {
        return (price[0]) * n;
    }
    int nottake = solve(i - 1, price, n);
    int take = INT_MIN;
    if (n >= (i + 1))
    {
        take = price[i] + solve(i, price, n - i - 1);
    }
    return max(take, nottake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = price[0] * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (j >= (i + 1))
            {
                take = price[i] + dp[i][j - i - 1];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
}
