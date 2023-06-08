// link https://leetcode.com/problems/repeated-string-match/

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string temp = "";
        int count = 0;
        while (temp.size() < b.size())
        {
            temp += a;
            count++;
        }
        if (found(temp, b))
        {
            return count;
        }
        count++;
        temp += a;
        if (found(temp, b))
            return count;
        return -1;
    }
    bool found(string &s, string &pat)
    {
        int m = pat.size();
        int n = s.size();
        int h = 1, p = 0, t = 0;
        int q = 101, d = 256;
        int i, j;
        for (i = 0; i < m - 1; i++)
        {
            h = (h * d) % q;
        }
        for (i = 0; i < m; i++)
        {
            t = (d * t + s[i]) % q;
            p = (d * p + pat[i]) % q;
        }
        for (i = 0; i <= n - m; i++)
        {
            if (p == t)
            {
                for (j = 0; j < m; j++)
                {
                    if (s[i + j] != pat[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    return true;
                }
            }
            if (i < n - m)
            {
                t = (d * (t - s[i] * h) + s[i + m]) % q;
                if (t < 0)
                {
                    t = t + q;
                }
            }
        }
        return false;
    }
};