/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/path-sum/

int flag = 0;
void sum(TreeNode *root, int B)
{
    if (root == NULL)
        return;
    if (B - root->val == 0 && root->left == NULL && root->right == NULL)
    {
        flag = 1;
        return;
    }
    sum(root->left, B - root->val);
    sum(root->right, B - root->val);
}
int Solution::hasPathSum(TreeNode *A, int B)
{
    flag = 0;
    sum(A, B);
    return flag;
}