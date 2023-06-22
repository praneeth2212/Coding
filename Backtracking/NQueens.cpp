// link https://www.interviewbit.com/problems/nqueens/

bool canplace(vector<string> &ans, int n, int x, int y)
{
    for (int k = 0; k < x; k++)
    {
        if (ans[k][y] == 'Q')
        {
            return false;
        }
    }
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (ans[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (ans[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
void solve(vector<vector<string>> &ans, vector<string> &s, int n, int i)
{
    if (i >= n)
    {
        ans.push_back(s);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (canplace(s, n, i, j))
        {
            s[i][j] = 'Q';
            solve(ans, s, n, i + 1);
        }
        s[i][j] = '.';
    }
    return;
}
vector<vector<string>> Solution::solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> s(n);
    string str = "";
    for (int i = 0; i < n; i++)
    {
        str = str + ".";
    }
    for (int i = 0; i < n; i++)
    {
        s[i] = str;
    }
    solve(ans, s, n, 0);
    return ans;
}
