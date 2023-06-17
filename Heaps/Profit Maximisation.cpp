// link https://www.interviewbit.com/problems/profit-maximisation/

int Solution::solve(vector<int> &a, int b)
{
    priority_queue<int> pq;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }
    int ans = 0;
    while (b--)
    {
        int c = pq.top();
        ans += c;
        pq.pop();
        pq.push(c - 1);
    }
    return ans;
}
