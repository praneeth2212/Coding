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

//  link https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                TreeNode *t = q.front();
                v.push_back(t->val);
                q.pop();
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};