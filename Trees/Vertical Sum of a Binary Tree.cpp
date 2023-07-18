/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  link https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

void preorder(TreeNode *A, map<TreeNode *, int> &mp, int k)
{
    if (A == NULL)
    {
        return;
    }
    mp[A] = k;
    if (A->left)
    {
        preorder(A->left, mp, k - 1);
    }
    if (A->right)
    {
        preorder(A->right, mp, k + 1);
    }
}
vector<int> Solution::verticalSum(TreeNode *A)
{
    if (A == NULL)
    {
        return {};
    }
    map<TreeNode *, int> mp;
    map<int, vector<int>> m1;
    vector<int> ans;
    preorder(A, mp, 0);
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        m1[mp[node]].push_back(node->val);
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }
    auto it = m1.begin();
    vector<vector<int>> v;
    while (it != m1.end())
    {
        v.push_back(it->second);
        it++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            sum = sum + v[i][j];
        }
        ans.push_back(sum);
    }
    return ans;
}
