class Solution
{
public:
    int maxProfit(vector<int> &a)
    {
        int n = a.size();
        int ans = 0, k = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] < k)
            {
                k = a[i];
            }
            if (a[i] - k > ans)
            {
                ans = a[i] - k;
            }
        }
        return ans;
    }
};