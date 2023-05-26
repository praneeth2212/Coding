// link https://leetcode.com/problems/3sum/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {
        vector<vector<int>> ans;
        set<vector<int>> se;
        sort(a.begin(), a.end());
        int n = a.size();
        int j, k;
        for (int i = 0; i < n; i++)
        {
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                if ((a[i] + a[j] + a[k]) > 0)
                {
                    k--;
                }
                else if ((a[i] + a[j] + a[k]) < 0)
                {
                    j++;
                }
                else
                {
                    se.insert({a[i], a[j], a[k]});
                    j++;
                    k--;
                }
            }
        }
        for (auto it : se)
        {
            ans.push_back(it);
        }
        return ans;
    }
};