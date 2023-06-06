// link https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        int n = a.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end())
            {
                cnt++;
            }
            else
            {
                mp[a[i]]++;
            }
            if (mp.find(b[i]) != mp.end())
            {
                cnt++;
            }
            else
            {
                mp[b[i]]++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};