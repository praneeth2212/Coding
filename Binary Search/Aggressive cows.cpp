// link https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;

int possible(vector<int> s, int m)
{
    int cnt = 1, n = s.size();
    int i = 0, j = 1;
    while (j < n)
    {
        if ((s[j] - s[i]) >= m)
        {
            cnt++;
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int st = 0, e = s[n - 1] - s[0];
        int ans = -1;
        while (st <= e)
        {
            int m = st + (e - st) / 2;
            if (possible(s, m) >= c)
            {
                ans = m;
                st = m + 1;
            }
            else if (possible(s, m) < c)
            {
                e = m - 1;
            }
        }
        cout << ans << endl;
    }
}