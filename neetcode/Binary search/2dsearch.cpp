// link https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &a, int t)
    {
        int s = 0;
        int m = a.size();
        int n = a[0].size();
        int e = m * n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (a[mid / n][mid % n] == t)
            {
                return true;
            }
            else if (a[mid / n][mid % n] < t)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return false;
    }
};