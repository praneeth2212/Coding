//  link https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

int Solution::trailingZeroes(int A)
{
    int n = A;
    int ans = 0;
    for (int i = 5; n / i; i = i * 5)
    {
        ans += n / i;
    }
    return ans;
}
