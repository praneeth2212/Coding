/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/max-depth-of-binary-tree/

int Solution::maxDepth(TreeNode *A)
{
    if (A == NULL)
    {
        return 0;
    }
    int h1 = maxDepth(A->left);
    int h2 = maxDepth(A->right);
    return 1 + max(h1, h2);
}
