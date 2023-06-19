// link https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &a)
{
    int n = a.size();
    int right[n], left[n];
    left[0] = a[0];
    right[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = min(left[i], right[i]);
        ans = ans + k - a[i];
    }
    return ans;
}
