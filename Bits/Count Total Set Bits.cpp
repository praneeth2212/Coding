// link https://www.interviewbit.com/problems/count-total-set-bits/

int Solution::solve(int n)
{
    if (n == 0)
    {
        return 0;
    }
    long long int p = 0, ans = 0;
    while (pow(2, p) <= n)
    {
        p++;
    }
    p--;
    ans = p * pow(2, p) / 2 + (n - pow(2, p) + 1) + solve(n - pow(2, p));
    ans %= 1000000007;
    return ans;
}
