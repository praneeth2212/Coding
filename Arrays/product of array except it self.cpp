// link https://leetcode.com/problems/product-of-array-except-self/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &a)
    {
        int tp = 1;
        int n = a.size();
        vector<int> ans;
        bool flag = false;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                count++;
                flag = true;
                continue;
            }
            tp *= a[i];
        }
        if (!flag)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(tp / a[i]);
            }
        }
        else if (flag && count == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 0)
                {
                    ans.push_back(tp);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};