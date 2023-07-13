// link https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

ListNode *Solution::swapPairs(ListNode *A)
{
    if (A == NULL || A->next == NULL)
    {
        return A;
    }
    ListNode *temp = A;
    ListNode *ans = A->next, *prev = NULL;
    while (temp != NULL && temp->next != NULL)
    {
        ListNode *t1 = temp->next;
        temp->next = temp->next->next;
        t1->next = temp;
        // cout<<temp->val<<" "<<t1->val<<" "<<t1->next->val;

        if (prev != NULL)
            prev->next = t1;
        prev = temp;
        temp = temp->next;
    }
    return ans;
}
