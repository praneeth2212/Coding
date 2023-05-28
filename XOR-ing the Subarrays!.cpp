// link https://www.interviewbit.com/problems/xor-ing-the-subarrays/

int Solution::solve(vector<int> &a)
{
    int n = a.size();
    if (n % 2 == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans ^= a[i];
        }
    }
    return ans;
}
