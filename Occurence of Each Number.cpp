// link https://www.interviewbit.com/problems/occurence-of-each-number/

vector<int> Solution::findOccurences(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    sort(a.begin(), a.end());
    int c = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            c++;
        }
        else
        {
            ans.push_back(c);
            c = 1;
        }
    }
    ans.push_back(c);
    return ans;
}
