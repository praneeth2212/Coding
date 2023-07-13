// link https://www.interviewbit.com/problems/right-view-of-binary-tree/

void rightview(TreeNode *root, map<int, int> &mp, vector<int> &ans, int k)
{
    if (root == nullptr)
        return;
    if (mp[k] < 1)
    {
        mp[k]++;
        ans.push_back(root->val);
    }
    rightview(root->right, mp, ans, k + 1);
    rightview(root->left, mp, ans, k + 1);
}
vector<int> Solution::solve(TreeNode *A)
{
    vector<int> ans;
    map<int, int> mp;
    if (A == nullptr)
        return ans;
    rightview(A, mp, ans, 0);
    return ans;
}