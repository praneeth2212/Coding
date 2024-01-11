// link https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
class dsu
{
    vector<int> rank, parent, size;

public:
    dsu(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findupar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int upu = findupar(u);
        int upv = findupar(v);
        if (upu == upv)
            return;
        if (rank[upu] < rank[upv])
        {
            parent[upu] = upv;
        }
        else if (rank[upu] > rank[upv])
        {
            parent[upv] = upu;
        }
        else
        {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjnode}});
            }
        }
        dsu ds(V);
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto it : edges)
        {
            int ewt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findupar(u) != ds.findupar(v))
            {
                ans += ewt;
                ds.unionbyrank(u, v);
            }
        }
        return ans;
    }
};