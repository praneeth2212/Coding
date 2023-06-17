// link https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int a, vector<int> &b)
{
    int m = 1000000007;
    priority_queue<int> pq;
    int n = b.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(b[i]);
    }
    int ans = 0;
    while (a--)
    {
        int c = (pq.top());
        ans = (ans % m + c % m);
        ans = ans % m;
        c = (c / 2);
        pq.pop();
        pq.push(c);
    }
    return ans % m;
}
