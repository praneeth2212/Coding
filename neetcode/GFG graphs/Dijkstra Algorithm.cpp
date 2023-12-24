// link https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ans(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        ans[S] = 0;
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            for (auto it : adj[n])
            {
                int edge = it[0];
                int wei = it[1];
                if (wt + wei < ans[edge])
                {
                    ans[edge] = wt + wei;
                    pq.push({ans[edge], edge});
                }
            }
        }
        return ans;
    }
};