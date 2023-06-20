// link https://www.interviewbit.com/problems/combination-sum-ii/

void comboSum(vector<int> &v, int ans, vector<vector<int>> &arr, vector<int> p, int l, int b)
{
    int n = v.size();
    for (int i = l; i < n; i++)
    {
        ans += v[i];
        p.push_back(v[i]);
        if (ans == b)
            arr.push_back(p);
        if (ans < b)
            comboSum(v, ans, arr, p, i + 1, b);
        ans -= v[i];
        p.pop_back();
    }
    return;
}
vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    int n = A.size();
    vector<vector<int>> arr;
    vector<int> p;
    sort(A.begin(), A.end());
    comboSum(A, 0, arr, p, 0, B);
    set<vector<int>> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    arr.clear();
    for (auto it : s)
    {
        arr.push_back(it);
    }
    return arr;
}