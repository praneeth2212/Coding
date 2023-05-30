// link https://www.interviewbit.com/problems/highest-score/

int Solution::highestScore(vector<vector<string>> &A)
{
    unordered_map<string, pair<int, int>> map;

    for (auto v : A)
    {
        string name = v[0];
        int marks = stoi(v[1]);
        map[name].first += marks;
        map[name].second++;
    }

    int curr_avg = 0;
    int max_avg = 0;

    for (auto v : map)
    {
        curr_avg = ((v.second).first) / ((v.second).second);
        max_avg = max(max_avg, curr_avg);
    }
    return max_avg;
}