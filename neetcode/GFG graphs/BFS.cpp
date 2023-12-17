// link https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> ans;
        vector<int> vis(V + 1, false);
        int s = 0;
        vis[s] = 1;
        q.push(s);
        while (!q.empty())
        {
            int t = q.front();
            ans.push_back(t);
            q.pop();
            for (int i : adj[t])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return ans;
    }
};