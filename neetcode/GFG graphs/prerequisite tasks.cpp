// link https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
class Solution
{
public:
    bool isPossible(int V, int P, vector<pair<int, int>> &p)
    {
        // Code here
        vector<int> adj[V];
        for (auto it : p)
        {
            adj[it.second].push_back(it.first);
        }
        int in[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                in[it]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for (auto it : adj[t])
            {
                in[it]--;
                if (in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (ans.size() == V)
        {
            return true;
        }
        return false;
    }
};