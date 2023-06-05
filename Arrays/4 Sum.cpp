// link https://www.interviewbit.com/problems/4-sum/

vector<vector<int>> Solution::fourSum(vector<int> &a, int b)
{
    vector<vector<int>> ans;
    int n = a.size();
    sort(a.begin(), a.end());
    set<vector<int>> se;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                int cs = a[i] + a[j] + a[k] + a[l];
                if ((cs) == b)
                {
                    se.insert({a[i], a[j], a[k], a[l]});
                    k++;
                }
                else if ((cs) > b)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    for (auto it : se)
    {
        ans.push_back(it);
    }
    return ans;
}
