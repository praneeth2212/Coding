// link https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/

int days(vector<int> a, int c)
{
    int ans = 0;
    int n = a.size();
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        cs += a[i];
        if (cs < c)
        {
            if (i == n - 1)
            {
                ans++;
                break;
            }
            continue;
        }
        else if (cs == c)
        {
            ans++;
            cs = 0;
        }
        else if (cs > c)
        {
            ans++;
            cs = 0;
            i--;
        }
    }
    return ans;
}

int Solution::solve(vector<int> &a, int b)
{
    int s = INT_MIN;
    int e = 0;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        s = max(s, a[i]);
        e += a[i];
    }
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        int q = days(a, m);
        if (q == b)
        {
            ans = m;
            e = m - 1;
        }
        else if (q < b)
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return ans;
}