/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// link https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *t = root;
        while (t != NULL)
        {
            if (p->val > t->val && q->val > t->val)
            {
                t = t->right;
            }
            else if (p->val < t->val && q->val < t->val)
            {
                t = t->left;
            }
            else
            {
                return t;
            }
        }
        return NULL;
    }
};  