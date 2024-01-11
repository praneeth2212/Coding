// link https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution
{
public:
    void bfs(queue<pair<int, int>> q, vector<vector<int>> &vis, vector<vector<int>> &h)
    {
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            vis[r][c] = 1;
            q.pop();
            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < h.size() && nc >= 0 && nc < h[0].size() && h[r][c] <= h[nr][nc] && !vis[nr][nc])
                {
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        vector<vector<int>> ans;
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> visp(n, vector<int>(m, 0));
        vector<vector<int>> visa(n, vector<int>(m, 0));
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;
        for (int i = m - 1; i >= 0; i--)
        {
            qp.push({0, i});
        }
        for (int i = n - 1; i >= 0; i--)
        {
            qp.push({i, 0});
        }
        for (int i = m - 1; i >= 0; i--)
        {
            qa.push({n - 1, i});
        }
        for (int i = n - 1; i >= 0; i--)
        {
            qa.push({i, m - 1});
        }
        bfs(qp, visp, h);
        bfs(qa, visa, h);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visp[i][j] && visa[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};