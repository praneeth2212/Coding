/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  link https://leetcode.com/problems/subtree-of-another-tree/
class Solution
{
public:
    bool same(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
        {
            return true;
        }
        if (t1 == NULL || t2 == NULL || t1->val != t2->val)
        {
            return false;
        }
        return (same(t1->left, t2->left) && same(t1->right, t2->right));
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL || subRoot == NULL)
        {
            return false;
        }
        if (same(root, subRoot))
        {
            return true;
        }
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};