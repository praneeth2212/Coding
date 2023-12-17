// link https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
class Solution
{
public:
    // Function to find the number of islands.
    void bfs(int r, int c, vector<vector<char>> &g, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        int n = g.size();
        int m = g[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && g[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &g)
    {
        // Code here
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '1' && !vis[i][j])
                {
                    ans++;
                    bfs(i, j, g, vis);
                }
            }
        }
        return ans;
    }
};