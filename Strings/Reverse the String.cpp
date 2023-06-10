// link https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A)
{
    string result;
    int n = A.size();
    int i = 0;
    while (i < n)
    {
        while (i < n && A[i] == ' ')
            i++;
        if (i >= n)
            break;
        int j = i + 1;
        while (j < n && A[j] != ' ')
            j++;
        string sub = A.substr(i, j - i);
        if (result.size() == 0)
            result = sub;
        else
            result = sub + " " + result;
        i = j + 1;
    }
    return result;
}