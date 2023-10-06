class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int t)
    {
        int n = a.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (a[i] + a[j] > t)
            {
                j--;
            }
            else if (a[i] + a[j] < t)
            {
                i++;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};