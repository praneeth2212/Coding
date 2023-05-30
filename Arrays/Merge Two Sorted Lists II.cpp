// link https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/
void Solution::merge(vector<int> &a, vector<int> &b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = a.size() + b.size() - 1;
    a.resize(a.size() + b.size());
    while (i >= 0 && j >= 0)
    {
        if (a[i] > b[j])
        {
            a[k] = a[i];
            k--;
            i--;
        }
        else if (a[i] < b[j])
        {
            a[k] = b[j];
            k--;
            j--;
        }
        else
        {
            a[k] = b[j];
            k--;
            j--;
            a[k] = a[i];
            k--;
            i--;
        }
    }
    while (i >= 0)
    {
        a[k] = a[i];
        k--;
        i--;
    }
    while (j >= 0)
    {
        a[k] = b[j];
        k--;
        j--;
    }
}
