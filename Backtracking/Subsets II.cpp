// link https://www.interviewbit.com/problems/subsets-ii/

vector<vector<int>> result;
void backtrack(vector<int> &temp, vector<int> nums, int index)
{
    result.push_back(temp);
    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        backtrack(temp, nums, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> Solution::subsetsWithDup(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<int> temp;
    backtrack(temp, A, 0);
    vector<vector<int>> res = result;
    result.clear();
    return res;
}