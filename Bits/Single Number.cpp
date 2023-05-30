//  link https://www.interviewbit.com/problems/single-number/

int Solution::singleNumber(const vector<int> &a)
{
    int n = a.size();
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t ^= a[i];
    }
    return t;
}
