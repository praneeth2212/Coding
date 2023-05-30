// link  https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
        {
            r = 1;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (a[0][i] == 0)
        {
            c = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }
    if (r == 1)
    {
        for (int i = 0; i < n; i++)
        {
            a[i][0] = 0;
        }
    }
    if (c == 1)
    {
        for (int i = 0; i < m; i++)
        {
            a[0][i] = 0;
        }
    }
}
