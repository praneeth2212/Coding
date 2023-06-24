// link https://leetcode.com/problems/reverse-linked-list-ii/description/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int length = right - left + 1;
        if (!head || head->next == NULL || length == 1)
            return head;

        // finding node at left-1
        ListNode *curr = head;
        for (int i = 1; i < left - 1; i++)
        {
            if (curr)
                curr = curr->next;
            else
                break;
        }
        ListNode *left_half = (left == 1) ? NULL : curr;
        curr = (left == 1) ? curr : curr->next;

        // finding node at right+1
        ListNode *right_half = head;
        for (int i = 1; i <= right; i++)
        {
            if (right_half)
                right_half = right_half->next;
            else
                break;
        }
        ListNode *prev = right_half;

        while (curr && length)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            length--;
        }
        if (left_half == NULL)
            return prev;
        left_half->next = prev;
        return head;
    }
};