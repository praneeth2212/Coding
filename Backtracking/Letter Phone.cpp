// link https://www.interviewbit.com/problems/letter-phone/

void solve(string &A, vector<string> &key, int pos, string &temp, vector<string> &ans)
{
    if (pos == A.size())
    {
        ans.push_back(temp);
        return;
    }

    for (auto p : key[A[pos] - '0'])
    {
        temp.push_back(p);
        solve(A, key, pos + 1, temp, ans);
        temp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A)
{
    vector<string> hash = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string temp = "";
    solve(A, hash, 0, temp, ans);
    return ans;
}