/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

TreeNode *Solution::flatten(TreeNode *A)
{
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *curr = dummy;
    stack<TreeNode *> st;
    st.push(A);
    while (!st.empty())
    {
        TreeNode *l = st.top()->left;
        TreeNode *r = st.top()->right;
        curr->right = st.top();
        st.pop();
        curr->left = NULL;
        curr = curr->right;
        if (r)
            st.push(r);
        if (l)
            st.push(l);
    }
    return (dummy->right);
}
