
// link https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);
int solve(int i, int j, vector<vector<char>> &v, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && v[i][j] == '*')
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = solve(i - 1, j, v, dp) % mod;
    int left = solve(i, j - 1, v, dp) % mod;
    return dp[i][j] = (up + left) % mod;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(n - 1, n - 1, v, dp);
}
