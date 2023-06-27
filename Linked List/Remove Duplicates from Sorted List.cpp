// link https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

ListNode *Solution::deleteDuplicates(ListNode *a)
{
    ListNode *s = a;
    ListNode *f = a;
    ListNode *t1 = a;
    ListNode *temp = s;
    while (t1->next != NULL)
    {
        t1 = t1->next;
    }
    int c = a->val;
    while (f != NULL)
    {
        if (c != f->val)
        {
            s->next = f;
            c = f->val;
            s = s->next;
        }
        if (t1->val == f->val)
        {
            s->next = NULL;
            break;
        }
        f = f->next;
    }
    return temp;
}
