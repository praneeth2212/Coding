// link https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
    int peak(vector<int> &a)
    {
        int n = a.size();
        int s = 0, e = n - 1; // s=0 e=1
        int ans = 0;
        while (s <= e)
        {                            // 0<=1
            int m = (e - s) / 2 + s; // 0

            if (a[m] >= a[0])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1; // e=-1
                ans = m;   //
            }
        }
        return ans;
    }
    int search(vector<int> &a, int t)
    {
        int n = a.size();
        int i = 0, s, e;
        if (a.size() == 1)
        {
            i = 0;
        }
        else
        {
            i = peak(a);
        }
        if (t == a[i])
        {
            return i;
        }
        s = i;
        e = n - 1;
        while (s <= e)
        {
            int m = (e - s) / 2 + s;
            if (t == a[m])
            {
                return m;
            }
            else if (t < a[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        s = 0;
        e = i - 1;
        while (s <= e)
        {
            int m = (e - s) / 2 + s;
            if (t == a[m])
            {
                return m;
            }
            else if (t < a[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return -1;
    }
};