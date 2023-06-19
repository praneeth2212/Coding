// link https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &a)
{
    int n = a.size();
    int leftsmall[n], rightsmall[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            leftsmall[i] = 0;
        }
        else
        {
            leftsmall[i] = s.top() + 1;
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            rightsmall[i] = n - 1;
        }
        else
        {
            rightsmall[i] = s.top() - 1;
        }
        s.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (a[i] * (rightsmall[i] - leftsmall[i] + 1)));
    }
    return ans;
}
