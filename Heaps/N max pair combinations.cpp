// link https://www.interviewbit.com/problems/n-max-pair-combinations/

bool rev(int a, int b)
{
    return b < a;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end(), rev);
    sort(B.begin(), B.end(), rev);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    int k = 0;
    while (k < n)
    {
        pq.push(A[k] + B[k]);
        k++;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if ((A[i] + B[j]) > pq.top())
                {
                    pq.pop();
                    pq.push(A[i] + B[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans(n, 0);
    int c = 0;
    while (c < n)
    {
        ans[c] = pq.top();
        pq.pop();
        c++;
    }

    sort(ans.begin(), ans.end(), rev);
    return ans;
}