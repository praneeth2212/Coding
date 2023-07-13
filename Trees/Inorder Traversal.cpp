// link https://www.interviewbit.com/problems/inorder-traversal/

vector<int> Solution::inorderTraversal(TreeNode *A)
{
    stack<TreeNode *> s;
    vector<int> v;
    if (A == NULL)
        return v;
    TreeNode *curr = A->left;
    s.push(A);
    while (!s.empty() || curr)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        TreeNode *temp = s.top();
        s.pop();
        v.push_back(temp->val);
        curr = temp->right;
    }
    return v;
}
