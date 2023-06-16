// link  https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string s)
{

    unordered_map<char, int> mp;

    queue<char> q;

    string res = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (!q.empty() && s[i] == q.front())
        {
            q.pop();

            while (!q.empty() && mp[q.front()] > 1)
            {
                q.pop();
            }
        }

        if (mp.find(s[i]) == mp.end())
        {
            q.push(s[i]);
        }

        if (q.empty())
        {
            res.push_back('#');
        }
        else
        {
            res.push_back(q.front());
        }

        mp[s[i]]++;
    }

    return res;
}
