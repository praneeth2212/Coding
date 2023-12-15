// link https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> ans;
    void calc(int index, vector<int> &nums, vector<int> &curr)
    {
        if (index >= nums.size())
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        calc(index + 1, nums, curr);
        curr.pop_back();
        calc(index + 1, nums, curr);
        return;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        ans.clear();
        vector<int> tmp;
        calc(0, nums, tmp);
        return ans;
    }
};