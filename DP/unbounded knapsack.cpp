
// link https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
int solve(int i, int w, vector<int> &profit, vector<int> &weight)
{
    if (i == 0)
    {
        if (w >= weight[0])
        {
            return profit[i] * (w / weight[0]);
        }
        return 0;
    }
    int nottake = solve(i - 1, w, profit, weight);
    int take = 0;
    if (w >= weight[i])
    {
        take = profit[i] + solve(i, w - weight[i], profit, weight);
    }
    return max(take, nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i <= w; i++)
    {
        if (i >= weight[0])
        {
            dp[0][i] = profit[0] * (i / weight[0]);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (weight[i] <= j)
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][w];
}