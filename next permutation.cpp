// link https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &a)
{
    int k = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i + 1] > a[i])
        {
            k = i;
            break;
        }
    }
    for (int i = n - 1; i >= k && k != -1; i--)
    {
        if (a[i] > a[k])
        {
            swap(a[i], a[k]);
            break;
        }
    }
    sort(a.begin() + k + 1, a.end());
    return a;
}
