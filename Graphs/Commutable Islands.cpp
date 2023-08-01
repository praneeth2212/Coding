// kruskal algorithm

// Time Complexity = O(ElogE + EV)
// which can be further optimised by union by rank and path compression to O(ElogE + ElogV)

// link https://www.interviewbit.com/problems/commutable-islands/

bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int findparent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return findparent(parent[v], parent);
}
int Solution::solve(int a, vector<vector<int>> &b)
{
    sort(b.begin(), b.end(), comp);
    vector<int> parent(a + 1);
    for (int i = 1; i <= a; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    int ans = 0;
    while (count < a - 1)
    {
        int srcparent = findparent(b[i][0], parent);
        int destparent = findparent(b[i][1], parent);
        if (srcparent != destparent)
        {
            ans += b[i][2];
            parent[destparent] = srcparent;
            count++;
        }
        i++;
    }
    return ans;
}