// link https://www.interviewbit.com/problems/counting-subarrays/
int Solution::solve(vector<int> &a, int b)
{
    int i = 0, ans = 0, cs = 0;
    int n = a.size();
    for (int j = 0; j < n; j++)
    {
        cs += a[j];
        while (cs >= b)
        {
            cs -= a[i];
            i++;
        }
        if (cs < b)
        {
            ans += (j - i + 1);
        }
    }
    return ans;
}
