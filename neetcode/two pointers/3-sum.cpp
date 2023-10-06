class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            int k = i + 1, j = n - 1;
            while (k < j)
            {
                int sum = a[i] + a[k] + a[j];
                if (sum > 0)
                {
                    j--;
                }
                else if (sum < 0)
                {
                    k++;
                }
                else
                {
                    s.insert({a[i], a[k], a[j]});
                    k++;
                    j--;
                }
            }
        }
        for (auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};