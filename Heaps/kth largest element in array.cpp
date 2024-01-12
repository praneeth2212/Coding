// link https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> mh;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mh.push(nums[i]);
        }
        for (int i = 0; i < k - 1; i++)
        {
            mh.pop();
        }
        return mh.top();
    }
};