// link https://www.interviewbit.com/problems/merge-k-sorted-arrays/

vector<int> Solution::solve(vector<vector<int>> &a)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            pq.push(a[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
