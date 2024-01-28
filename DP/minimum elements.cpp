
// https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
int solve(int i, vector<int> &num, int x, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (x % num[0] == 0)
        {
            return x / num[0];
        }
        return 1e9;
    }
    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }
    int nottake = solve(i - 1, num, x, dp);
    int take = INT_MAX;
    if (num[i] <= x)
    {
        take = 1 + solve(i, num, x - num[i], dp);
    }
    return dp[i][x] = min(take, nottake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = solve(n - 1, num, x, dp);
    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}