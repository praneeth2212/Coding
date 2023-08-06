// link https://www.interviewbit.com/problems/path-in-directed-graph/

bool dfs(int start, vector<int> adj[], int vis[], int V)
{
    vis[start] = 1;
    for (auto it : adj[start])
    {
        if (!vis[it])
        {
            if (it == V)
                return true;
            else
            {
                vis[it] = 1;
                if (dfs(it, adj, vis, V) == true)
                    return true;
            }
        }
    }
    return false;
}

int Solution::solve(int V, vector<vector<int>> &B)
{
    vector<int> adj[V + 1];
    int vis[V + 1] = {0};
    for (auto it : B)
    {
        adj[it[0]].push_back(it[1]);
    }
    for (int i = 1; i <= V; i++)
    {
        if (dfs(i, adj, vis, V))
            return 1;
    }
    return 0;
}