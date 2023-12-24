// link https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
class Solution
{
public:
    vector<vector<string>> findSequences(string b, string e, vector<string> &w)
    {
        // code here
        unordered_set<string> st(w.begin(), w.end());
        queue<vector<string>> q;
        q.push({b});
        vector<string> use;
        use.push_back(b);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            if (v.size() > level)
            {
                level++;
                for (auto it : use)
                {
                    st.erase(it);
                }
                use.clear();
            }
            string word = v.back();
            if (word == e)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(v);
                }
                else if (ans[0].size() == v.size())
                {
                    ans.push_back(v);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char og = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word) > 0)
                    {
                        v.push_back(word);
                        q.push(v);
                        use.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = og;
            }
        }
        return ans;
    }
};