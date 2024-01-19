
https : // www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

        bool
        subsetSumToK(int n, int k, vector<int> &arr)
{
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = notTaken || taken;
        }
    }
    return dp[n - 1][k];
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    if (s % 2)
    {
        return false;
    }
    else
    {
        return subsetSumToK(n, s / 2, arr);
    }
}
