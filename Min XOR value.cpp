// link https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, a[i] ^ a[i + 1]);
    }
    return ans;
}
