// link https://leetcode.com/problems/swim-in-rising-water/
class Solution
{
public:
    int swimInWater(vector<vector<int>> &g)
    {
        int n = g.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({g[0][0], {0, 0}});
        vector<vector<int>> vis(g.size(), vector<int>(g.size(), 0));
        vis[0][0] = 1;
        while (!pq.empty())
        {
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == n - 1 && c == n - 1)
            {
                return time;
            }
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g.size() && !vis[nr][nc])
                {
                    pq.push({max(time, g[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};