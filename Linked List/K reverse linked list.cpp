// https://www.interviewbit.com/problems/k-reverse-linked-list/

ListNode *Solution::reverseList(ListNode *A, int B)
{
    if (A == NULL)
        return NULL;
    ListNode *curr = A;
    ListNode *prev = NULL;
    int x = B;
    while (B--)
    {
        ListNode *Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    A->next = reverseList(curr, x);
    return prev;
}