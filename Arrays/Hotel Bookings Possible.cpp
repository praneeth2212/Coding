// link https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &a, vector<int> &d, int k)
{
    int n = a.size();
    vector<pair<int, char>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(a[i], 'a'));
        v.push_back(make_pair(d[i], 'd'));
    }
    sort(v.begin(), v.end());
    int rc = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 'a')
        {
            rc++;
        }
        else
        {
            rc--;
        }
        if (rc > k)
        {
            return 0;
        }
    }
    return 1;
}