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

//  link https://leetcode.com/problems/binary-tree-right-side-view/
class Solution
{
public:
    vector<int> ans;
    queue<TreeNode *> q;
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.back();
            ans.push_back(temp->val);
            int n = q.size();
            while (n--)
            {
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};