// https://leetcode.com/problems/max-area-of-island/

class Solution
{
public:
    int bfs(map<pair<int, int>, bool> &vis, int c, int row, int col, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        c++;
        vis[{row, col}] = true;
        while (!q.empty())
        {
            auto t = q.front();
            int x = t.first;
            int y = t.second;
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if ((nx >= 0 && nx < grid.size()) && (ny >= 0 && ny < grid[0].size()) && (!vis[{nx, ny}]) && grid[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    vis[{nx, ny}] = true;
                    c++;
                }
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        map<pair<int, int>, bool> vis;
        int ans = 0, c = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (!vis[{row, col}] && grid[row][col] == 1)
                {
                    c = bfs(vis, 0, row, col, grid);
                    ans = max(c, ans);
                }
            }
        }
        return ans;
    }
};