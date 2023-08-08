// link https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{
public:
    void dfs(int i, vector<int> &ans, vector<bool> &vis, int V, vector<int> adj[])
    {
        if (vis[i])
        {
            return;
        }
        vis[i] = true;
        ans.push_back(i);
        for (int j : adj[i])
        {
            if (!vis[j])
            {
                dfs(j, ans, vis, V, adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> vis(V + 1, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, ans, vis, V, adj);
            }
        }
        return ans;
    }
};