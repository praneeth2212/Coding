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
//  link https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

class Solution
{
public:
    void func(TreeNode *root, vector<int> &ans)
    {
        stack<TreeNode *> s;
        TreeNode *curr = root->left;
        s.push(root);
        while (!s.empty() || curr)
        {
            while (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            TreeNode *temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            curr = temp->right;
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        func(root, ans);
        return ans[k - 1];
    }
};