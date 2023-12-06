// link https://leetcode.com/problems/binary-search/

class Solution
{
public:
    int search(vector<int> &a, int t)
    {
        int n = a.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (a[m] == t)
            {
                return m;
            }
            else if (a[m] < t)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return -1;
    }
};