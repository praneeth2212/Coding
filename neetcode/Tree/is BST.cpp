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
//  link https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution
{
public:
    bool solve(TreeNode *&root, long long int mini, long long int maxi)
    {
        if (root == NULL)
            return true;
        if (root->val > mini && root->val < maxi)
        {
            return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
        }
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        long int mini = -4294967296;
        long int maxi = 4294967295;
        
        return solve(root, mini, maxi);
    }
};