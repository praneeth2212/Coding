// link https://www.interviewbit.com/problems/trailing-zeroes/

int Solution::solve(int a)
{
    int ans = 0;
    while (a > 0)
    {
        int lb = a & 1;
        if (!lb)
        {
            ans++;
        }
        else
        {
            break;
        }
        a = a >> 1;
    }
    return ans;
}
