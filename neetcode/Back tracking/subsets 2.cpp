// link https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    void helper(int idx, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++)
        {
            ds.push_back(nums[i]);
            helper(i + 1, ds, nums, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0, ds, nums, ans);
        set<vector<int>> s1;
        for (int i = 0; i < ans.size(); i++)
        {
            s1.insert(ans[i]);
        }
        ans.clear();
        for (auto it : s1)
        {
            ans.push_back(it);
        }
        return ans;
    }
};