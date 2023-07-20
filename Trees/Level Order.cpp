/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/level-order/

vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}
