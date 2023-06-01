// link https://www.interviewbit.com/problems/allocate-books/

bool check(vector<int> &a, int b, int m)
{
    int sc = 1, n = a.size(), ps = 0;
    for (int i = 0; i < n; i++)
    {
        if (ps + a[i] <= m)
        {
            ps += a[i];
        }
        else
        {
            sc++;
            ps = 0;
            ps += a[i];
        }
        if (sc > b || a[i] > m)
        {
            return false;
        }
    }
    return true;
}

int Solution::books(vector<int> &a, int b)
{
    int s = 0, e = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        e += a[i];
    }
    int ans = -1;
    if (n < b)
    {
        return -1;
    }
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (check(a, b, m))
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
