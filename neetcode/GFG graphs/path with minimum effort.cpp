// link https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &h)
    {
        // Code here
        int n = h.size();
        int m = h[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        while (!pq.empty())
        {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r == n - 1 && c == m - 1)
            {
                return diff;
            }
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int n1 = max(abs(h[nr][nc] - h[r][c]), diff);
                    if (n1 < dis[nr][nc])
                    {
                        dis[nr][nc] = n1;
                        pq.push({n1, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};