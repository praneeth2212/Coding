// link https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &a, int k)
    {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for (auto i : a)
        {
            mp[i]++;
        }
        for (auto &i : mp)
        {
            minh.push({i.second, i.first});
            if (minh.size() > k)
            {
                minh.pop();
            }
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};