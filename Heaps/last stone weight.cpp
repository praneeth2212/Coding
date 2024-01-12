
// link https://leetcode.com/problems/last-stone-weight/
class Solution
{
public:
    int lastStoneWeight(vector<int> &s)
    {
        priority_queue<int> pq;
        for (int i = 0; i < s.size(); i++)
        {
            pq.push(s[i]);
        }
        cout << pq.top() << endl;
        while (pq.size() != 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y)
            {
                if (pq.size() == 0)
                {
                    return 0;
                }
                continue;
            }
            else
            {
                cout << x << "  " << y << endl;
                pq.push(x - y);
            }
        }
        return pq.top();
    }
};