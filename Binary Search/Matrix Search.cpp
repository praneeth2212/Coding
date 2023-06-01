// link https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int>> &a, int target)
{
    int rows = a.size();
    int cols = a[0].size();
    int s = 0, e = (rows * cols) - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        int i = m / cols;
        int j = m % cols;
        if (a[i][j] == target)
        {
            return true;
        }
        else if (a[i][j] < target)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return false;
}
