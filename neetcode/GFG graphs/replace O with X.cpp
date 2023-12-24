// link https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
class Solution
{
public:
    void bfs(int r, int c, vector<vector<char>> mat, vector<vector<int>> &vis, int n, int m)
    {
        vis[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
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
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !vis[i][0])
            {
                bfs(i, 0, mat, vis, n, m);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O' && !vis[0][i])
            {
                bfs(0, i, mat, vis, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1])
            {
                bfs(i, m - 1, mat, vis, n, m);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[n - 1][i] == 'O' && !vis[n - 1][i])
            {
                bfs(n - 1, i, mat, vis, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};