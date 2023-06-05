// link https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    int res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        unordered_map<double, int> mp;
        double x1 = (double)A[i], y1 = (double)B[i];
        int same = 0;
        for (int j = i + 1; j < B.size(); j++)
        {
            double x2 = (double)A[j], y2 = (double)B[j];
            if (x1 == x2 && y1 == y2)
            {
                same++;
            }
            else if (x2 == x1)
            {
                mp[INT_MAX]++;
            }
            else
            {
                double slope = (y2 - y1) / (x2 - x1);
                mp[slope]++;
            }
        }
        int temp = 0;
        for (auto x : mp)
        {
            temp = max(temp, x.second);
        }
        temp++;
        temp = temp + same;
        res = max(res, temp);
    }
    return res;
}