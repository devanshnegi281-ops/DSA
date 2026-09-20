struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    while(head != NULL && head->next != NULL)
    {
        struct ListNode *curr = head;
        struct ListNode *next = head->next;
        prev->next = next;
        curr->next = next->next;
        next->next = curr;
        prev = curr;
        head = curr->next;
    }
    return dummy.next;
}
