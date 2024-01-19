
// link https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int ninjaTraining(int n, vector<vector<int>> &p)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(p[0][1], p[0][2]);
    dp[0][1] = max(p[0][0], p[0][2]);
    dp[0][2] = max(p[0][1], p[0][0]);
    for (int i = 1; i < n; i++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int maxi = p[i][task] + dp[i - 1][task];
                    dp[i][last] = max(dp[i][last], maxi);
                }
            }
        }
    }
    return dp[n - 1][3];
}