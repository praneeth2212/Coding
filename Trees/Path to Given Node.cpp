/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// link https://www.interviewbit.com/problems/path-to-given-node/

bool helper(TreeNode *a, int b, vector<int> &ans, bool &flg)
{
    if (a == NULL)
    {
        return false;
    }
    if (flg == false)
    {
        ans.push_back(a->val);
    }
    if (a->val == b)
    {
        flg = true;
        return true;
    }
    bool l = helper(a->left, b, ans, flg);
    bool r = helper(a->right, b, ans, flg);
    if (l == false && r == false && flg == false)
    {
        ans.pop_back();
        return false;
    }
    return true;
}
vector<int> Solution::solve(TreeNode *a, int b)
{
    vector<int> ans;
    bool flg = false;
    helper(a, b, ans, flg);
    return ans;
}
