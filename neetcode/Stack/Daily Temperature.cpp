class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && t[i] > s.top().first)
            {
                pair<int, int> temp = s.top();
                s.pop();
                ans[temp.second] = (i - temp.second);
            }
            s.push({t[i], i});
        }
        return ans;
    }
};