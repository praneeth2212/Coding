// link https://www.interviewbit.com/problems/palindrome-list/

ListNode *reverse(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;
    ListNode *prev = NULL;
    ListNode *curr = A;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int Solution::lPalin(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return 1;
    ListNode *temp_A = A;
    int c1 = 0;
    while (temp_A)
    {
        c1++;
        temp_A = temp_A->next;
    }
    int count = c1 / 2 - 1;
    temp_A = A;
    while (count--)
        temp_A = temp_A->next;
    ListNode *oth_node = reverse(temp_A->next);
    temp_A->next = NULL;
    while (oth_node && A)
    {
        if (oth_node->val != A->val)
            return 0;
        oth_node = oth_node->next;
        A = A->next;
    }
    return 1;
}