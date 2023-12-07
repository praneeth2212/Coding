/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  link https://leetcode.com/problems/reorder-list/
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || (!head->next) || (!head->next->next))
        {
            return;
        }
        ListNode *ptr = head;
        stack<ListNode *> s;
        int n = 0;
        while (ptr)
        {
            s.push(ptr);
            ptr = ptr->next;
            n++;
        }
        ListNode *p = head;
        for (int j = 0; j < n / 2; j++)
        {
            ListNode *t = s.top();
            s.pop();
            t->next = p->next;
            p->next = t;
            p = p->next->next;
        }
        p->next = NULL;
    }
};