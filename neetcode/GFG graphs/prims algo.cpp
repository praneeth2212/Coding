// link https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        vector<int> vis(V, 0);
        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (vis[node] == 1)
            {
                continue;
            }
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int edwt = it[1];
                if (!vis[adjnode])
                {
                    pq.push({edwt, adjnode});
                }
            }
        }
        return sum;
    }
};