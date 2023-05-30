// link https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

int func(vector<int> &a, int b)
{
    int n = a.size();
    unordered_map<int, int> mp;
    int ans = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        mp[a[j]]++;
        while (mp.size() > b)
        {
            mp[a[i]]--;
            if (mp[a[i]] == 0)
            {
                mp.erase(a[i]);
            }
            i++;
        }
        ans += (j - i + 1);
        j++;
    }
    return ans;
}
int Solution::solve(vector<int> &a, int b)
{
    int c1 = func(a, b);
    int c2 = func(a, b - 1);
    return c1 - c2;
}
