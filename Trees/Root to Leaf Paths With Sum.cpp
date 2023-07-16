/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

void solve(TreeNode *root, int B, vector<vector<int>> &ans, vector<int> v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->val);
    if (B - root->val == 0 && root->right == NULL && root->left == NULL)
    {
        ans.push_back(v);
    }
    else
    {
        solve(root->left, B - root->val, ans, v);
        solve(root->right, B - root->val, ans, v);
    }
}
vector<vector<int>> Solution::pathSum(TreeNode *A, int B)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(A, B, ans, v);
    return ans;
}
