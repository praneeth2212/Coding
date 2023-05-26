class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int t)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
        {
            if (mp.find(t - a[i]) == mp.end())
            {
                mp[a[i]] = i;
            }
            else
            {
                return {mp[t - a[i]], i};
            }
        }
        return {-1};
    }
};