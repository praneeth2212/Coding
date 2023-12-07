/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  link https://leetcode.com/problems/linked-list-cycle/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head;
        while (f)
        {
            s = s->next;
            f = f->next;
            if (!f)
            {
                return NULL;
            }
            f = f->next;
            if (s == f)
            {
                break;
            }
        }
        if (!f)
        {
            return NULL;
        }
        while (s != f)
        {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};