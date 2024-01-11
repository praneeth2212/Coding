
// link https://leetcode.com/problems/network-delay-time/
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for (auto it : adj[node])
            {
                int edtime = it.second;
                int adjn = it.first;
                if (time + edtime < dist[adjn])
                {
                    dist[adjn] = time + edtime;
                    pq.push({time + edtime, adjn});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9)
            {
                return -1;
            }
            else
            {
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};