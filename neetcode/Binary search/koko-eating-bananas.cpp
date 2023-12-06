// link https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    bool check(int m, vector<int> &p, int h)
    {
        long long s = 0;
        for (int i = 0; i < p.size(); i++)
        {
            s += ((p[i] / m) + ((p[i] % m) != 0));
        }
        if (s > h)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int minEatingSpeed(vector<int> &p, int h)
    {
        int s = 1;
        int e = 0;
        int n = p.size();
        for (int i = 0; i < n; i++)
        {
            e = max(e, p[i]);
        }
        int ans = 0;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (check(m, p, h))
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
};