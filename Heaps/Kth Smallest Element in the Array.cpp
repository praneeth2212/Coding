// link https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int Solution::kthsmallest(const vector<int> &A, int B)
{
    priority_queue<int> q;
    for (int i = 0; i < A.size(); i++)
    {
        q.push(A[i]);
        if (q.size() > B)
        {
            q.pop();
        }
    }
    return q.top();
}