// link https://www.codingninjas.com/studio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
int solve(int i, int j, string &s, string &sub)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (s[i] == sub[j])
    {
        return solve(i - 1, j - 1, s, sub) + solve(i - 1, j, s, sub);
    }
    return solve(i - 1, j, s, sub);
}
int distinctSubsequences(string &s, string &sub)
{
    // Write your code here.
    long long n = s.size();
    long long m = sub.size();
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == sub[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
                dp[i][j] = (dp[i - 1][j]) % mod;
        }
    }
    return dp[n][m] % mod;
}
