/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

int sum = 0;
void solve(TreeNode *root, string s)
{
    if (root == NULL)
        return;
    s += to_string(root->val);
    s = to_string(stoi(s) % 1003);
    if (!root->left && !root->right)
        sum += stoi(s) % 1003;
    solve(root->left, s);
    solve(root->right, s);
}

int Solution::sumNumbers(TreeNode *A)
{
    sum = 0;
    solve(A, "");
    return sum % 1003;
}
