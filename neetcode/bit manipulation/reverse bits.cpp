// link https://leetcode.com/problems/reverse-bits/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        int b = 0;
        while (n > 0)
        {
            ans = ans | (n % 2) << (31 - b);
            b++;
            n = n >> 1;
        }
        return ans;
    }
};