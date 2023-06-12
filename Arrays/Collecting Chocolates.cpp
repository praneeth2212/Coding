// link https://leetcode.com/problems/collecting-chocolates/

class Solution
{
public:
    long long minCost(vector<int> &a, int x)
    {
        int n = a.size();
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            v[0][i] = a[i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j >= 1)
                {
                    v[i][j] = v[i - 1][j - 1];
                }
                else
                {
                    v[i][j] = v[i - 1][n - 1];
                }
            }
        }
        vector<int> cols(n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (long long)a[i];
            cols[i] = a[i];
        }
        long long fans = ans;
        for (int i = 1; i < n; i++)
        {
            long long cans = ans;
            cans += (long long)x;
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] < cols[j])
                {
                    cans -= cols[j];
                    cols[j] = v[i][j];
                    cans += v[i][j];
                }
            }
            fans = min(fans, cans);
            ans = cans;
        }
        return fans;
    }
};