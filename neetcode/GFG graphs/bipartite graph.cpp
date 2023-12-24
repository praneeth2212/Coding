// link https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
class Solution
{
public:
    bool check(int i, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto it : adj[t])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[t];
                    q.push(it);
                }
                else if (color[it] == color[t])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here

        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};