// link https://www.interviewbit.com/problems/redundant-braces/
int Solution::braces(string a)
{
    int i = 0;
    stack<char> s;
    while (i < a.size())
    {
        char c = a[i];
        if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
        {
            s.push(c);
        }
        if (c == ')')
        {
            if (s.top() == '(')
            {
                return 1;
            }
            else
            {
                while (!s.empty() && s.top() != '(')
                {
                    s.pop();
                }
                s.pop();
            }
        }
        i++;
    }
    return 0;
}
