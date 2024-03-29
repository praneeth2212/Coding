// link https://leetcode.com/problems/number-of-1-bits/

class Solution
{
public:
    int hammingWeight(uint32_t n)
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
};