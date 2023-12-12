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

//  link https://leetcode.com/problems/balanced-binary-tree/
class Solution
{
public:
    bool ans;
    int func(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        int left = func(node->left);
        int right = func(node->right);

        if (abs(left - right) > 1)
            ans = false;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        ans = true;
        func(root);
        return ans;
    }
};