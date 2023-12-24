// link https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
class Solution
{
public:
    bool dfs(int i, int vis[], int pathvis[], vector<int> adj[], int check[])
    {
        vis[i] = 1;
        pathvis[i] = 1;
        check[i] = 0;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, pathvis, adj, check) == true)
                {
                    check[i] = 0;
                    return true;
                }
            }
            else if (pathvis[it])
            {
                check[i] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        vector<int> ans;
        int check[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, pathvis, adj, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i])
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};