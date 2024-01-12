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
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<pair<int, pair<int, int>>> adj;
        int n = points.size();
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x2 - x1) + abs(y2 - y1);
                adj.push_back({dis, {i, j}});
            }
        }
        dsu ds(n);
        sort(adj.begin(), adj.end());
        int ans = 0;
        for (auto it : adj)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findupar(u) != ds.findupar(v))
            {
                ans += wt;
                ds.unionbyrank(u, v);
            }
        }
        return ans;
    }
};