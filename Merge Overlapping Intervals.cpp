//  link https://www.interviewbit.com/problems/merge-overlapping-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &a)
{
    vector<Interval> ans;
    sort(a.begin(), a.end(), [](const Interval &a, const Interval &b)
         { return a.start < b.start; });
    int n = a.size();
    Interval b = a[0];
    for (int i = 1; i < n; i++)
    {
        if (b.end >= a[i].start)
        {
            b.end = max(b.end, a[i].end);
            b.start = min(b.start, a[i].start);
        }
        else
        {
            ans.push_back(b);
            b = a[i];
        }
    }
    ans.push_back(b);
    return ans;
}
