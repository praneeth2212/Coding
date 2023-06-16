// link https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &a)
{
    int n = a.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(a[0]);
    ans[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty())
        {
            if (s.top() >= a[i])
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(a[i]);
    }
    return ans;
}
