// link https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

void preorder(TreeNode *A, map<TreeNode *, int> &slopes, int slope)
{
    if (A == NULL)
        return;
    slopes[A] = slope;
    if (A->left)
        preorder(A->left, slopes, slope - 1);
    if (A->right)
        preorder(A->right, slopes, slope + 1);
}
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{
    map<TreeNode *, int> slopes;
    map<int, vector<int>> levels;
    vector<vector<int>> ans;
    preorder(A, slopes, 0);
    queue<TreeNode *> q;
    if (A == NULL)
        return ans;
    q.push(A);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        levels[slopes[node]].push_back(node->val);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    auto it = levels.begin();
    while (it != levels.end())
    {
        ans.push_back(it->second);
        it++;
    }
    return ans;
}