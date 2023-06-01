// link https://www.interviewbit.com/problems/addition-without-summation/

int Solution::addNumbers(int a, int b)
{
    while (b != 0)
    {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
