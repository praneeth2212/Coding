// link https://www.interviewbit.com/problems/combination-sum/

void solve(vector<int> &a, int b, int k, vector<vector<int>> &ans, vector<int> &temp, int i)
{
    if (k == b)
    {
        ans.push_back(temp);
        return;
    }
    while (i < a.size() && k <= b)
    {
        temp.push_back(a[i]);
        solve(a, b, k + a[i], ans, temp, i);
        i++;
        temp.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &a, int b)
{
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(a, b, 0, ans, temp, 0);
    return ans;
}
