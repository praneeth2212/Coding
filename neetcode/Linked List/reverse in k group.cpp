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

//  link https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
        {
            return head;
        }
        int count = 0;
        ListNode *current = head;
        while (current && count < k)
        {
            current = current->next;
            count++;
        }
        if (count < k)
        {
            return head;
        }
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        current = head;
        for (int i = 0; i < k; i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head->next = reverseKGroup(current, k);
        return prev;
    }
};