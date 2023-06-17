// link https://www.interviewbit.com/problems/amazing-subarrays/

int Solution::solve(string a)
{
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
        {
            ans += (n - 1 - i + 1);
        }
    }
    return ans % 10003;
}
