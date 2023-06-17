// link https://www.interviewbit.com/problems/nextgreater/

vector<int> Solution::nextGreater(vector<int> &nums1)
{

    vector<int> ans(nums1.size(), -1);

    stack<int> s;

    for (int i = 0; i < nums1.size(); i++)
    {

        while (!s.empty() && nums1[s.top()] < nums1[i])
        {

            ans[s.top()] = nums1[i];

            s.pop();
        }

        s.push(i);
    }

    return ans;
}