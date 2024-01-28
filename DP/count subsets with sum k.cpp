
// link https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    if (k < 0)
    {
        return 0;
    }
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= k; t++)
        {
            int nottake = dp[i - 1][t];
            int take = 0;
            if (arr[i - 1] <= t)
            {
                take = dp[i][t - arr[i]];
            }
            dp[i][t] = (take + nottake) % mod;
        }
    }
    return dp[n - 1][k] % mod;
}
