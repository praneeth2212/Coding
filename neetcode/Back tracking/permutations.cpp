// link https://leetcode.com/problems/permutations/

class Solution
{
public:
    void helper(vector<int> &a, vector<vector<int>> &ans, int n, int i)
    {
        if (i == n - 1)
        {
            ans.push_back(a);
            return;
        }
        for (int k = i; k < n; k++)
        {
            // cout<<"befor"<<"k="<<k<<"i="<<i<<endl;
            swap(a[k], a[i]);
            helper(a, ans, n, i + 1);
            // cout<<"after"<<"k="<<k<<"i="<<i<<endl;
            swap(a[k], a[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        helper(nums, ans, n, 0);
        return ans;
    }
};