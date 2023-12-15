// link https://leetcode.com/problems/powx-n/

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        if (n >= 0)
        {
            while (n > 0)
            {
                int lb = n & 1;
                if (lb)
                {
                    ans *= x;
                }
                x = x * x;
                n = n >> 1;
            }
        }
        else
        {
            n = abs(n);
            while (n > 0)
            {
                int lb = n & 1;
                if (lb)
                {
                    ans /= x;
                }
                x = x * x;
                n = n >> 1;
            }
        }
        return ans;
    }
};