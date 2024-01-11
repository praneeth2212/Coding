// link https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces
class dsu
{
    vector<int> parent, rank;

public:
    dsu(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findupar(int node)
    {
        if (parent[node] == node)
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
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        dsu ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionbyrank(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.findupar(i) == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};