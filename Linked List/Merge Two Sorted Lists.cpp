// link https://leetcode.com/problems/merge-two-sorted-lists/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp = new ListNode();
        ListNode *temphead = temp;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val > temp2->val)
            {
                temphead->next = temp2;
                temphead = temphead->next;
                temp2 = temp2->next;
            }
            else if (temp1->val < temp2->val)
            {
                temphead->next = temp1;
                temphead = temphead->next;
                temp1 = temp1->next;
            }
            else
            {
                temphead->next = temp2;
                temphead = temphead->next;
                temp2 = temp2->next;
                temphead->next = temp1;
                temphead = temphead->next;
                temp1 = temp1->next;
            }
        }
        while (temp1 != NULL)
        {
            temphead->next = temp1;
            temphead = temphead->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            temphead->next = temp2;
            temphead = temphead->next;
            temp2 = temp2->next;
        }
        return temp->next;
    }
};