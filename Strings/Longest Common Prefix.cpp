// link https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A)
{
    string s;
    for (int i = 0; i < A[0].size(); i++)
    {
        char c = A[0][i];
        for (int j = 1; j < A.size(); j++)
        {
            if (c != A[j][i])
                return s;
        }
        s += c;
    }
    return s;
}