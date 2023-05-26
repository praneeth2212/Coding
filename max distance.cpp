// link https://www.interviewbit.com/problems/max-distance/
int Solution::maximumGap(const vector<int> &a)
{
    if (a.size() == 1)
    {
        return a.size() - 1;
    }
    int ans = 0;
    vector<pair<int, int>> b;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        b.push_back(make_pair(a[i], i));
    }
    sort(b.begin(), b.end());
    int minpos = b[0].second;
    for (int i = 1; i < n; i++)
    {
        if (b[i].second > minpos)
        {
            ans = max(ans, b[i].second - minpos);
        }
        minpos = min(minpos, b[i].second);
    }
    return ans;
}
