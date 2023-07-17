/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/least-common-ancestor/

bool findX(TreeNode *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (findX(root->left, x) || findX(root->right, x))
        return true;
    return false;
}
TreeNode *LCA(TreeNode *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    if (root->val == a)
    {
        return root;
    }
    if (root->val == b)
    {
        return root;
    }
    TreeNode *l = LCA(root->left, a, b);
    TreeNode *r = LCA(root->right, a, b);
    if (l && r)
        return root;
    if (l)
        return l;
    return r;
}
int Solution::lca(TreeNode *root, int A, int B)
{
    bool isA = findX(root, A);
    bool isB = findX(root, B);
    if (isA && isB)
    {
        TreeNode *node = LCA(root, A, B);
        return node->val;
    }
    return -1;
}
