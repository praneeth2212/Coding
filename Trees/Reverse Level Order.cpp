// link https://www.interviewbit.com/problems/reverse-level-order/

vector<int> Solution::solve(TreeNode *A)
{
    TreeNode *head = A;
    queue<TreeNode *> q;
    q.push(head);
    vector<int> ans;
    while (q.empty() == false)
    {
        TreeNode *temp = q.front();
        ans.push_back(temp->val);
        q.pop();
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}