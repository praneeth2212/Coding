// link https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flight, int src, int dst, int K)
    {
        // Code here
        vector<pair<int, int>> adj[n];
        for (auto it : flight)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            if (stop > K)
            {
                continue;
            }
            for (auto it : adj[node])
            {
                if (dis + it.second < dist[it.first] && stop <= K)
                {
                    dist[it.first] = dis + it.second;
                    q.push({stop + 1, {it.first, it.second + dis}});
                }
            }
        }
        if (dist[dst] == 1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};