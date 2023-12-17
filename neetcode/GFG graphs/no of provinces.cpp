// link https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
class Solution
{
private:
    void dfs(int i, vector<int> a[], int vis[])
    {
        vis[i] = 1;
        for (auto it : a[i])
        {
            if (!vis[it])
            {
                dfs(it, a, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<int> a[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, a, vis);
            }
        }
        return cnt;
    }
};