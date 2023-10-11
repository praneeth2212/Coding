class Solution
{
public:
    void help(int n, int o, int c, vector<string> &ans, string &s)
    {
        if (o + c == 2 * n)
        {
            ans.push_back(s);
            return;
        }
        if (o < n)
        {
            s += '(';
            help(n, o + 1, c, ans, s);
            s.pop_back();
        }
        if (o > c)
        {
            s += ')';
            help(n, o, c + 1, ans, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s;
        help(n, 0, 0, ans, s);
        return ans;
    }
};