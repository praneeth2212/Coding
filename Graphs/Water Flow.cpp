// link https://www.interviewbit.com/problems/water-flow/

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>> q, vector<vector<bool>> &v, int n, int m, vector<vector<int>> &a)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == true)
            {
                continue;
            }
            if (a[x][y] <= a[nx][ny])
            {
                v[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int Solution::solve(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<bool>> blue(n, vector<bool>(m, false));
    vector<vector<bool>> red(n, vector<bool>(m, false));
    queue<pair<int, int>> qb, qr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                qb.push({i, j});
                blue[i][j] = true;
            }
            if (i == n - 1 || j == m - 1)
            {
                qr.push({i, j});
                red[i][j] = true;
            }
        }
    }
    bfs(qb, blue, n, m, a);
    bfs(qr, red, n, m, a);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blue[i][j] && red[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}
