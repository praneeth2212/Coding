// link https://www.interviewbit.com/problems/painters-partition-problem/

bool func(vector<long long> &d, int A, long long mid)
{
    long long sum = 0, p = 1;

    for (int i = 0; i < d.size(); i++)
    {
        if (p > A)
            return false;

        if (sum + d[i] <= mid)
            sum += d[i];
        else
        {
            sum = d[i];
            p++;
        }
    }

    if (p <= A)
        return true;
    return false;
}

int Solution::paint(int A, int B, vector<int> &C)
{

    long long sum = 0, maxi = INT_MIN;
    vector<long long> d(C.size(), 0);

    for (int i = 0; i < C.size(); i++)
    {
        d[i] = 1ll * B * C[i];
        maxi = max(maxi, d[i]);
        sum += (d[i]);
    }

    if (A > C.size())
        return maxi;

    long long s = maxi, e = sum, ans;

    while (s <= e)
    {
        long long mid = s + (e - s) / 2;

        if (func(d, A, mid))
        {
            e = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans % 10000003;
}