// link https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string a)
{
    int n = a.size();
    stack<char> s;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
        }
        else if (a[i] == ')' && s.top() == '(')
        {
            s.pop();
        }
        else
        {
            s.push(a[i]);
        }
    }
    if (s.empty())
    {
        return 1;
    }
    return 0;
}
