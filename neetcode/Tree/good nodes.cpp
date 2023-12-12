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

//  link https://leetcode.com/problems/count-good-nodes-in-binary-tree/
class Solution
{
public:
    int x = 0;
    void helper(TreeNode *root, int y)
    {
        if (root == NULL)
        {
            return;
        }
        y = max(y, root->val);
        helper(root->left, y);
        helper(root->right, y);
        if (root->val >= y)
        {
            x++;
        }
    }

    int goodNodes(TreeNode *root)
    {
        helper(root, root->val);
        root->left = NULL;
        root->right = NULL;
        return x;
    }
};