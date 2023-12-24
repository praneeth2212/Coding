// link https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
class Solution
{
public:
    void dfs(int i, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            int v = it.first;
            if (!vis[v])
            {
                dfs(v, adj, vis, st);
            }
        }
        st.push(i);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        int vis[N] = {0};
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        vector<int> ans(N);
        for (int i = 0; i < N; i++)
        {
            ans[i] = 1e9;
        }
        ans[0] = 0;
        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            for (auto it : adj[t])
            {
                int v = it.first;
                int wt = it.second;
                if (ans[t] + wt < ans[v])
                {
                    ans[v] = ans[t] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (ans[i] == 1e9)
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};