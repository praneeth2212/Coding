// link https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
class Solution
{
public:
    int wordLadderLength(string s, string t, vector<string> &w)
    {
        // Code here
        queue<pair<string, int>> q;
        q.push({s, 1});
        unordered_set<string> st(w.begin(), w.end());
        st.erase(s);
        while (!q.empty())
        {
            string w = q.front().first;
            int t1 = q.front().second;
            q.pop();
            if (w == t)
            {
                return t1;
            }
            for (int i = 0; i < w.size(); i++)
            {
                char c = w[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    w[i] = ch;
                    if (st.find(w) != st.end())
                    {
                        q.push({w, t1 + 1});
                        st.erase(w);
                    }
                }
                w[i] = c;
            }
        }
        return 0;
    }
};