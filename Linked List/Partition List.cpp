// link https://www.interviewbit.com/problems/partition-list/

ListNode *Solution::partition(ListNode *A, int B)
{
    ListNode *p = new ListNode(0);
    ListNode *q = new ListNode(0);
    ListNode *a = p, *b = q;
    ListNode *s = A;
    while (s != NULL)
    {
        if (s->val < B)
        {
            a->next = s;
            a = a->next;
        }
        else if (s->val >= B)
        {
            b->next = s;
            b = b->next;
        }
        s = s->next;
    }
    b->next = NULL;
    a->next = q->next;
    return p->next;
}
