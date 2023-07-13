/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// link https://www.interviewbit.com/problems/invert-the-binary-tree/

TreeNode *Solution::invertTree(TreeNode *a)
{
    if (a == NULL)
    {
        return a;
    }
    invertTree(a->left);
    invertTree(a->right);
    TreeNode *t = a->left;
    a->left = a->right;
    a->right = t;
    return a;
}
