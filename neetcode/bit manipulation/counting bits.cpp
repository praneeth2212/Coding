// link https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    int func(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            int lb = n & 1;
            if (lb)
            {
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = func(i);
            ans[i] = k;
        }
        return ans;
    }
};