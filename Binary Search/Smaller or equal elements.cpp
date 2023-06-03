// link https://www.interviewbit.com/problems/smaller-or-equal-elements/

int Solution::solve(vector<int> &a, int b)
{
    int s = 0;
    int e = a.size() - 1;
    int ans = 0;
    if (a.size() == 1 && a[0] <= b)
    {
        return 1;
    }
    else if (a.size() == 1)
    {
        return 0;
    }
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (a[m] == b)
        {
            ans = m;
            s = m + 1;
        }
        else if (a[m] < b)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return (ans + 1);
}
