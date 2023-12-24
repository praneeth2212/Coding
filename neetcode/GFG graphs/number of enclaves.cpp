// link https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
class Solution
{
public:
    void bfs(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &vis, int n, int m)
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
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &mat)
    {
        // Code here
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 1 && !vis[i][0])
            {
                bfs(i, 0, mat, vis, n, m);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 1 && !vis[0][i])
            {
                bfs(0, i, mat, vis, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][m - 1] == 1 && !vis[i][m - 1])
            {
                bfs(i, m - 1, mat, vis, n, m);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[n - 1][i] == 1 && !vis[n - 1][i])
            {
                bfs(n - 1, i, mat, vis, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1 && !vis[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};