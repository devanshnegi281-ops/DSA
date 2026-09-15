/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode less = {0, NULL}, greater = {0, NULL};
    struct ListNode *ptr1 = &less, *ptr2 = &greater;
    while (head)
    {
        if (head->val < x)
        {
            ptr1->next = head;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr2->next = head;
            ptr2 = ptr2->next;
        }
        head = head->next;
    }
    ptr2->next = NULL;
    ptr1->next = greater.next;
    return less.next;
}