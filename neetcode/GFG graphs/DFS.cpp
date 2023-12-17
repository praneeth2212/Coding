// link https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(int i, vector<bool> &vis, vector<int> adj[], vector<int> &ans)
    {
        if (vis[i])
        {
            return;
        }
        vis[i] = true;
        ans.push_back(i);
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, ans);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V + 1, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, ans);
            }
        }
        return ans;
    }
};