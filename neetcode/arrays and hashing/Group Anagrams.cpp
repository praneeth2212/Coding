class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &s)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            string t = s[i];
            sort(t.begin(), t.end());
            mp[t].push_back(s[i]);
        }
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};