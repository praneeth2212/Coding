// link https://leetcode.com/problems/missing-number/

class Solution
{
public:
    int missingNumber(vector<int> &a)
    {
        int ans = 0;
        int n = a.size();
        for (int i = 0; i <= n; i++)
        {
            ans ^= i;
        }
        for (int i = 0; i < n; i++)
        {
            ans ^= a[i];
        }
        return ans;
    }
};