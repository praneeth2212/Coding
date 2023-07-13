/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// link https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    int count = 0;
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int size = q.size();
        count++;
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            v.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            q.pop();
        }
        if (count % 2 != 0)
        {
            ans.push_back(v);
        }
        else
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
        }
    }
    return ans;
}
