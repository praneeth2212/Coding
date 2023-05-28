//  link https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int a)
{
    int ans = 0;
    while (a > 0)
    {
        int lb = a & 1;
        a = a >> 1;
        if (lb)
        {
            ans++;
        }
    }
    return ans;
}
