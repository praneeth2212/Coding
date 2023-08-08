// link https://www.interviewbit.com/problems/file-search/

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int ind)
{
    vis[ind] = true;
    for (auto i : adj[ind])
    {
        if (!vis[i])
        {
            dfs(adj, vis, i);
        }
    }
}
int Solution::breakRecords(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> adj(n + 1);
    for (auto &i : mat)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<bool> vis(n + 1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i);
            ans += 1;
        }
    }
    return ans;
}