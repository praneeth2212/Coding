// link https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c)
{
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i] + b[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (i != j)
            {
                if ((a[i] + b[j]) > pq.top())
                {
                    pq.pop();
                    pq.push(a[i] + b[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    int cnt = 0;
    while (cnt < a.size())
    {
        ans.push_back(pq.top());
        pq.pop();
        cnt++;
    }
    sort(ans.begin(), ans.end(), greater<>());
    vector<int> ans1;
    int i = 0;
    while (i < c)
    {
        ans1.push_back(ans[i]);
        i++;
    }
    return ans1;
}
