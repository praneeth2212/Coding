class Solution
{
public:
    int leastInterval(vector<char> &t, int n)
    {
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        for (char i : t)
        {
            mp[i - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp[i])
            {
                pq.push(mp[i]);
            }
        }
        int ans = 0;
        while (!pq.empty())
        {
            vector<int> remain;
            int cycle = n + 1;
            while (cycle && !pq.empty())
            {
                int top = pq.top();
                pq.pop();
                if (top > 1)
                {
                    remain.push_back(top - 1);
                }
                ans++;
                --cycle;
            }
            for (int i = 0; i < remain.size(); i++)
            {
                pq.push(remain[i]);
            }
            if (pq.empty())
            {
                break;
            }
            ans += cycle;
        }
        return ans;
    }
};