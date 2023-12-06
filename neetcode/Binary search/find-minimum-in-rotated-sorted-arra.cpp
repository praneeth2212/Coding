// link https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution
{
public:
    int findMin(vector<int> &a)
    {
        int n = a.size();
        int s = 0, e = n - 1;
        int ans = 0;
        while (s <= e)
        {
            int m = (e - s) / 2 + s;

            if (a[m] >= a[0])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
                ans = m;
            }
        }
        return a[ans];
    }
};