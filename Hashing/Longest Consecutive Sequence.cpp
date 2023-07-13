// link https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &a)
{
    int n = a.size();
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i] - 1) > 0)
        {
            mp[a[i]] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] == true)
        {
            int j = 0, count = 0;
            while (mp.count(a[i] + j) > 0)
            {
                j++;
                count++;
            }
            if (count > ans)
            {
                ans = count;
            }
        }
    }
    return ans;
}
