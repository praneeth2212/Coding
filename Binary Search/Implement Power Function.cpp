// link https://www.interviewbit.com/problems/implement-power-function/

typedef long long ll;

int Solution::pow(int x, int n, int d)
{
    ll ans = 1;
    ll m = x;
    bool flag = true;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * m) % d;
        }
        m = (m * m) % d;
        n = n >> 1;
    }
    ll k = (abs(ans)) % d;
    if (ans < 0)
    {
        flag = false;
    }
    if (flag)
    {
        return k;
    }
    else
    {
        return (d - k);
    }
}
