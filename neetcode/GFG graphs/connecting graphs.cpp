// link https://www.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
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
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        dsu ds(n);
        int cntext = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findupar(u) == ds.findupar(v))
            {
                cntext++;
            }
            else
            {
                ds.unionbyrank(u, v);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findupar(i) == i)
            {
                cnt++;
            }
        }
        if (cntext >= (cnt - 1))
        {
            return cnt - 1;
        }
        return -1;
    }
};