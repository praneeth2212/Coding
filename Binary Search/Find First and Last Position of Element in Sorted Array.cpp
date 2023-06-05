// link https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution
{
public:
    vector<int> searchRange(vector<int> &a, int t)
    {
        int ans1 = 0, ans2 = 0;
        int n = a.size();
        int s = 0, e = n - 1;
        bool chk = false;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (a[m] == t)
            {
                ans1 = m;
                e = m - 1;
                chk = true;
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
        s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (a[m] == t)
            {
                ans2 = m;
                s = m + 1;
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
        if (chk)
        {
            return {ans1, ans2};
        }
        else
        {
            return {-1, -1};
        }
    }
};