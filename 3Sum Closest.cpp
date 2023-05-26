// link https://leetcode.com/problems/3sum-closest/
class Solution
{
public:
    int threeSumClosest(vector<int> &a, int t)
    {
        int n = a.size();
        int md = INT_MAX, ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int cd = abs(a[i] + a[j] + a[k] - t);
                if (cd < md)
                {
                    md = cd;
                    ans = a[i] + a[j] + a[k];
                }
                if (a[i] + a[j] + a[k] < t)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};