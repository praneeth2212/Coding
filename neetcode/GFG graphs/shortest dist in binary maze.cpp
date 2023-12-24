// link https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        if (source.first == destination.first && source.second == destination.second)
        {
            return 0;
        }
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while (!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && d + 1 < dis[nr][nc])
                {
                    dis[nr][nc] = d + 1;
                    if (nr == destination.first && nc == destination.second)
                    {
                        return d + 1;
                    }
                    q.push({d + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};