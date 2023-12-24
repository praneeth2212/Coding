// link https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(N, 1e9);
        ans[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto it : adj[t])
            {
                if (ans[t] + 1 < ans[it])
                {
                    ans[it] = ans[t] + 1;
                    q.push(it);
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