// link https://leetcode.com/problems/redundant-connection/

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
        int ulu = findupar(u);
        int ulv = findupar(v);
        if (ulv == ulu)
        {
            return;
        }
        if (rank[ulu] < rank[ulv])
        {
            parent[ulu] = ulv;
        }
        else if (rank[ulu] > rank[ulv])
        {
            parent[ulv] = ulu;
        }
        else
        {
            parent[ulv] = ulu;
            rank[ulu]++;
        }
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> ans;
        dsu ds(edges.size());
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findupar(u) != ds.findupar(v))
            {
                ds.unionbyrank(u, v);
            }
            else
            {
                ans = {u, v};
            }
        }
        return ans;
    }
};