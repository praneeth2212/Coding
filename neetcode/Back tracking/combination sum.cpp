// link https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    vector<vector<int>> ans;
    void func(int s, int i, vector<int> &a, vector<int> &b, int t)
    {
        if (s == t)
        {
            ans.push_back(b);
            return;
        }
        while (i < a.size() && s <= t)
        {
            b.push_back(a[i]);
            func(s + a[i], i, a, b, t);
            i++;
            b.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &a, int t)
    {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        ans.clear();
        vector<int> b;
        func(0, 0, a, b, t);
        return ans;
    }
};