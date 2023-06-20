// link https://www.interviewbit.com/problems/generate-all-parentheses-ii/

void solve(vector<string> &ans, string s, int n, int o, int c)
{
    if (o + c == (2 * n))
    {
        ans.push_back(s);
        return;
    }
    if (o < n)
    {
        s += "(";
        solve(ans, s, n, o + 1, c);
        s.pop_back();
    }
    if (o > c)
    {
        s += ")";
        solve(ans, s, n, o, c + 1);
        s.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";
    solve(ans, s, n, 0, 0);
    return ans;
}
