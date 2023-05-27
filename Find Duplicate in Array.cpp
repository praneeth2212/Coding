// link https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &a)
{
    int s = a[0];
    int f = a[a[0]];
    while (s != f)
    {
        s = a[s];
        f = a[a[f]];
    }
    f = 0;
    while (s != f)
    {
        s = a[s];
        f = a[f];
    }
    return s;
}
