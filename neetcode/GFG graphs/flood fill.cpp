// link https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
class Solution
{
public:
    void bfs(int sr, int sc, vector<vector<int>> &image, int nc, vector<vector<int>> &vis)
    {
        int k = image[sr][sc];
        image[sr][sc] = nc;
        vis[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int n = image.size();
        int m = image[0].size();
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == k && !vis[nrow][ncol])
                {
                    image[nrow][ncol] = nc;
                    // cout<<nrow<<"  "<<ncol<<endl;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(sr, sc, image, newColor, vis);
        return image;
    }
};