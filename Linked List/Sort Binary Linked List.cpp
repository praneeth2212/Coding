// link https://www.interviewbit.com/problems/sort-binary-linked-list/

ListNode *Solution::solve(ListNode *a)
{
    ListNode *temp = a;
    ListNode *temp1 = a;
    int c = 0, c1 = 0, c0 = 0;
    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            c0++;
        }
        else
        {
            c1++;
        }
        temp = temp->next;
        c++;
    }
    while (c0--)
    {
        a->val = 0;
        a = a->next;
    }
    while (c1--)
    {
        a->val = 1;
        a = a->next;
    }
    return temp1;
}
