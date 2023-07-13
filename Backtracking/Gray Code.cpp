// link https://www.interviewbit.com/problems/gray-code/

vector<int> Solution::grayCode(int a)
{
    int i, j;
    vector<int> ans;
    int largest = (int)(pow(2, a)) - 1;
    for (i = 0; i <= largest; i++)
    {
        ans.push_back(i ^ (i >> 1));
    }

    return ans;
}