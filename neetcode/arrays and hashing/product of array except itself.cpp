class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int c = 0;
        vector<int> ans(nums.size(), 0);
        for (auto i : nums)
        {
            if (i == 0)
            {
                c++;
            }
        }
        if (c >= 2)
        {
            return ans;
        }
        if (c == 1)
        {
            int pro = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    continue;
                }
                pro *= nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    ans[i] = pro;
                }
            }
            return ans;
        }
        else
        {
            int pro = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                pro *= nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                ans[i] = pro / nums[i];
            }
            return ans;
        }
    }
};