class Solution
{
public:
    bool isPalindrome(string s)
    {
        string st;
        for (int i = 0; i < s.size(); i++)
        {
            char c = tolower(s[i]);
            if (c >= 'a' && c <= 'z')
            {
                st.push_back(c);
            }
            if (c >= '0' && c <= '9')
            {
                st.push_back(c);
            }
        }
        int n = st.size();
        for (int i = 0; i < n; i++)
        {
            cout << st[i];
        }
        for (int i = 0; i < (n / 2); i++)
        {
            if (st[i] != st[n - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};