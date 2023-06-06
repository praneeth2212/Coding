// link https://www.interviewbit.com/problems/equal/

vector<int> Solution::equal(vector<int> &A)
{
    if (A.empty())
        return {};

    map<int, pair<int, int>> sum;
    vector<int> ans;
    int n = A.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sumab = A[i] + A[j];

            if (sum.find(sumab) == sum.end())
                sum[sumab] = make_pair(i, j);
            else
            {
                pair<int, int> p = sum[sumab];

                if (p.first < i && p.second != i && p.second != j)
                {
                    vector<int> temp;
                    temp.emplace_back(p.first);
                    temp.emplace_back(p.second);
                    temp.emplace_back(i);
                    temp.emplace_back(j);

                    if (ans.size() == 0)
                        ans = temp;
                    else
                    {
                        for (int t = 0; t < ans.size(); ++t)
                        {
                            if (ans[t] < temp[t])
                                break;
                            if (ans[t] > temp[t])
                            {
                                ans.clear();
                                ans = temp;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
