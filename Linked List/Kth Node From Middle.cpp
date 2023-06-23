// link https://www.interviewbit.com/problems/kth-node-from-middle/

int Solution::solve(ListNode *a, int b)
{
    ListNode *s = a;
    ListNode *f = a;
    int k = 0;
    while (f != NULL)
    {
        f = f->next;
        k++;
    }
    int c = (k / 2) - b;
    if (c == 0)
    {
        return a->val;
    }
    else if (c >= 0)
    {
        while (c--)
        {
            s = s->next;
        }
        return s->val;
    }
    return -1;
}
