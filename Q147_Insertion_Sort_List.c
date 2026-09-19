/**
Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (!head)
        return NULL;
    struct ListNode dummy = {0, head};
    struct ListNode* curr = head;
    while (curr && curr->next)
    {
        if (curr->next->val >= curr->val)
            curr = curr->next;
        else
        {
            struct ListNode* toInsert = curr->next;
            curr->next = toInsert->next;
            struct ListNode* prev = &dummy;
            while (prev->next->val < toInsert->val)
                prev = prev->next;

            toInsert->next = prev->next;
            prev->next = toInsert;
        }
    }
    return dummy.next;
}