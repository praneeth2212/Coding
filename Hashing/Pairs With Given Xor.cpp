// link https://www.interviewbit.com/problems/pairs-with-given-xor/

int Solution::solve(vector<int> &a, int b)
{
    int ans = 0;
    unordered_map<int, int> m;
    for (auto x : a)
    {
        if (m.find(x ^ b) != m.end())
        {
            ans++;
        }
        else
        {
            m[x]++;
        }
    }
    return ans;
}
