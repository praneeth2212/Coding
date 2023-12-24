// link https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i, int vis[], int pathvis[], vector<int> adj[])
    {
        vis[i] = 1;
        pathvis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, pathvis, adj) == true)
                {
                    return true;
                }
            }
            else if (pathvis[it])
            {
                return true;
            }
        }
        pathvis[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, pathvis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};