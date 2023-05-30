// link https://www.interviewbit.com/problems/pascal-triangle/
int bin(int n, int k)
{
    int res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
vector<vector<int>> Solution::solve(int a)
{
    vector<vector<int>> ans;
    for (int i = 0; i < a; i++)
    {
        vector<int> v;
        for (int j = 0; j <= i; j++)
        {
            v.push_back(bin(i, j));
        }
        ans.push_back(v);
    }
    return ans;
}
