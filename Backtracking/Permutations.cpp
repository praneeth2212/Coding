// link https://www.interviewbit.com/problems/permutations/discussion/

void solve(vector<vector<int>> &ans, int t, vector<int> &a, int i)
{
    if (i >= a.size() - 1)
    {
        ans.push_back(a);
        return;
    }
    for (int k = i; k < a.size(); k++)
    {
        swap(a[k], a[i]);
        solve(ans, a.size(), a, i + 1);
        swap(a[k], a[i]);
    }
}
vector<vector<int>> Solution::permute(vector<int> &a)
{
    vector<vector<int>> ans;
    vector<int> t;
    solve(ans, a.size(), a, 0);
    return ans;
}
