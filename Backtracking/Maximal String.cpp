// link https://www.interviewbit.com/problems/maximal-string/

string ans;
void solve2(string A, int B, int i)
{
    int n = A.length();
    if (B == 0 || i == n)
    {
        if (ans < A)
            ans = A;
        return;
    }
    // no swap
    solve2(A, B, i + 1);
    // swap
    for (int j = i; j < n; j++)
    {
        swap(A[i], A[j]);
        solve2(A, B - 1, i + 1);
        swap(A[i], A[j]);
    }
    return;
}
string Solution::solve(string A, int B)
{
    if (B == 0)
        return A;
    ans = A;
    solve2(A, B, 0);
    return ans;
}
