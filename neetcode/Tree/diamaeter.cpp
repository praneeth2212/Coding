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

//  link https://leetcode.com/problems/diameter-of-binary-tree/submissions/1115210489/
class Solution
{
public:
    int ans;
    int depth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int h1 = depth(root->left);
        int h2 = depth(root->right);
        ans = max(ans, h1 + h2);
        return 1 + max(h1, h2);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;
        depth(root);
        return ans;
    }
};