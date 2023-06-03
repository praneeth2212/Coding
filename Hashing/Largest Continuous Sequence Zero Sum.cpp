// link https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &a)
{
    unordered_map<int, int> m;
    int sum = 0, k = 0;
    vector<int> ans;
    int n = a.size();
    m[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (m.find(sum) != m.end())
        {
            if ((i - m[sum]) > k)
            {
                ans.clear();
                for (int j = m[sum] + 1; j <= i; j++)
                {
                    ans.push_back(a[j]);
                }
            }
            k = max(k, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    return ans;
}
