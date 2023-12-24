// link https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution
{
public:
    void dfs(int i, vector<int> adj[], int vis[], stack<int> &st)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(i);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            ans.push_back(t);
        }
        return ans;
    }
};