// link https://www.interviewbit.com/problems/path-in-matrix/

int Solution::checkPath(vector<vector<int>> &a)
{
    int n = a.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                q.push({i, j});
                a[i][j] = 0;
                break;
            }
        }
    }
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        auto temp = q.front();
        int x = temp.first, y = temp.second;
        q.pop();
        if (a[x][y] == 2)
            return 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (min(nx, ny) < 0 || nx >= n || ny >= n || a[nx][ny] == 0)
                continue;
            else if (a[nx][ny] == 2)
                return 1;
            q.push({nx, ny});
            a[nx][ny] = 0;
        }
    }
    return 0;
}