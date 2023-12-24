// link https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
class Solution
{
public:
    void bfs(int r, int c, vector<pair<int, int>> &v, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        v.push_back({0, 0});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    v.push_back({(nrow - r), (ncol - c)});
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    vector<pair<int, int>> v;
                    bfs(i, j, v, grid, vis);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};