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

// link https://leetcode.com/problems/add-two-numbers/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t = new ListNode();
        ListNode *th = t;
        int s = 0, c = 0;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        while (t1 || t2 || c)
        {
            s = 0;
            if (t1)
            {
                s += t1->val;
                t1 = t1->next;
            }
            if (t2)
            {
                s += t2->val;
                t2 = t2->next;
            }
            s += c;
            t->next = new ListNode(s % 10);
            t = t->next;
            c = s / 10;
        }
        return th->next;
    }
};