/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// link https://www.interviewbit.com/problems/balanced-binary-tree/

int findHeight(TreeNode *A)
{
    if (!A)
        return 0;
    int l = findHeight(A->left);
    int r = findHeight(A->right);
    if (l == -1 || r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;
    return 1 + max(l, r);
}

int Solution::isBalanced(TreeNode *A)
{
    if (findHeight(A) == -1)
        return 0;
    return 1;
}