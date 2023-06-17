// link https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &a, int b)
{
    int n = a.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == (i - b))
        {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= b - 1)
        {
            ans.push_back(a[dq.front()]);
        }
    }
    return ans;
}
