// link https://www.interviewbit.com/problems/distribute-in-circle/

int Solution::solve(int a, int b, int c)
{
    return (a + c - 1) % b;
}
