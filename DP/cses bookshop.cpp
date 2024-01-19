#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, total;
    cin >> n >> total;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prices[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pages[i] = x;
    }
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    for (int j = 0; j <= total; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][total];
}

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}