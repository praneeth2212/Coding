
// link https://leetcode.com/problems/k-closest-points-to-origin/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &p, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < p.size(); i++)
        {
            int t = p[i][0] * p[i][0] + p[i][1] * p[i][1];
            if (k > pq.size())
            {
                pq.push({t, {p[i][0], p[i][1]}});
            }
            else if (k == pq.size())
            {
                if (t < pq.top().first)
                {
                    pq.pop();
                    pq.push({t, {p[i][0], p[i][1]}});
                }
            }
            cout << pq.top().first << endl;
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            ;
            pq.pop();
        }
        return ans;
    }
};