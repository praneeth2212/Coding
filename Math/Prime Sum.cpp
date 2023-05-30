// link https://www.interviewbit.com/problems/prime-sum/

bool check(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A)
{
    vector<int> v(2);
    for (int i = 2; i * i <= A; i++)
    {
        if (check(i) && check(A - i))
        {
            v[0] = i;
            v[1] = A - i;
            return v;
        }
    }
}
