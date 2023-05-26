// link https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] <= n)
        {
            int j = a[i] - 1;
            if (a[j] != a[i])
            {
                swap(a[j], a[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != i + 1)
        {
            return (i + 1);
        }
    }
}
