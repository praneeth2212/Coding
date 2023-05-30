//  link https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &a)
{
    int n = a.size();
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        int mi = min(a[i], a[j]);
        ans = max(ans, (j - i) * mi);
        if (mi == a[i])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
