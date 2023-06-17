// link https://www.interviewbit.com/problems/anagrams/

vector<vector<int>> Solution::anagrams(const vector<string> &a)
{
    vector<vector<int>> ans;
    unordered_map<string, vector<int>> mp;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        sort(s.begin(), s.end());
        mp[s].push_back(i + 1);
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
