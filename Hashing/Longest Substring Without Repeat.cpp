// link https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string a)
{
    int ans = 0;
    int n = a.size();
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    while (j < n)
    {
        if (mp[a[j]] > 0)
        {
            i = max(mp[a[j]], i);
        }
        ans = max(ans, j - i + 1);
        mp[a[j]] = j + 1;
        j++;
    }
    return ans;
}
