// link https://www.interviewbit.com/problems/move-zeroes/

vector<int> Solution::solve(vector<int> &a)
{
    int n = a.size();
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[i] == 0 && a[j] != 0)
        {
            swap(a[i], a[j]);
            i++;
        }
        else if (a[i] != 0)
        {
            i++;
        }
        j++;
    }
    return a;
}
