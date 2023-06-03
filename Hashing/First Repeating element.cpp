// link https://www.interviewbit.com/problems/first-repeating-element/

int Solution::solve(vector<int> &A)
{
    unordered_map<int, int> m;
    for (auto x : A)
    {
        m[x]++;
    }
    for (auto x : A)
    {
        if (m[x] > 1)
        {
            return x;
        }
    }
    return -1;
}
