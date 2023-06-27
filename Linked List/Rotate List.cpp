// link https://www.interviewbit.com/problems/rotate-list/

ListNode *Solution::rotateRight(ListNode *A, int B)
{
    ListNode *temp = A;
    int n = 0;
    while (temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }
    n++;
    temp->next = A;
    temp = temp->next;
    B = B % n;
    int k = n - B, i = 1;
    while (i < k)
    {
        temp = temp->next;
        i++;
    }
    ListNode *ans = temp->next;
    temp->next = NULL;
    return ans;
}