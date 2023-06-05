// link https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            v[i] = 0;
        }
        else
        {
            v[i] = 1;
        }
    }
    unordered_map<int, int> m;
    int ans = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {

        currSum = currSum + v[i];
        if (currSum == B)
        {
            ans++;
        }
        if (m.find(currSum - B) != m.end())
        {
            ans = ans + (m[currSum - B]);
        }
        m[currSum]++;
    }

    return ans;
}
