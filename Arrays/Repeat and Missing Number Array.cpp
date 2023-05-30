// link https://www.interviewbit.com/problems/repeat-and-missing-number-array/

typedef long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &a)
{
    ll as = 0, es = 0, ass = 0, ess = 0;
    ll n = a.size();
    es = n * (n + 1) / 2;
    ess = n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < n; i++)
    {
        as += a[i];
        ass += ((ll)a[i] * (ll)a[i]);
    }
    long long int c = (es - as);
    long long int d = (ess - ass);
    long long int e = d / c;
    vector<int> ans;
    long long int f = (e + c);
    ans.push_back((e - c) / 2);
    ans.push_back((f) / 2);
    return ans;
}
