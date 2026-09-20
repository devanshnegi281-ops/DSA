/*
struct ListNode
{
    int val;
    struct ListNode *next;
};
*/
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* ptr = head;
    while(ptr != NULL && ptr->next != NULL)
    {
        if(ptr->val == ptr->next->val)
            ptr->next = ptr->next->next;
        else
            ptr = ptr->next;
    }
    return head;
}
