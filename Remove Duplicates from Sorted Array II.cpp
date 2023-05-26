// link https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A)
{
    int n = A.size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 2 && A[i] == A[i + 1] && A[i + 1] == A[i + 2])
        {
            continue;
        }
        else if (i < n - 2 && A[i] == A[i + 1] && A[i + 1] != A[i + 2])
        {
            A[k] = A[i];
            A[k + 1] = A[i + 1];
            k = k + 2;
            i++;
        }
        else
        {
            A[k] = A[i];
            k++;
        }
    }
    return k;
}